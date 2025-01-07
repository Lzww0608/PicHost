#ifndef __LOCK_H__
#define __LOCK_H__

#include "ostype.h"


// CLock类提供了一个跨平台的互斥锁实现
class CLock {
public:
    // 构造函数,初始化互斥锁
    CLock();
    // 析构函数,销毁互斥锁
    virtual ~CLock();

    // 加锁操作
    void lock();
    // 解锁操作
    void unlock();
    // 获取底层pthread互斥锁对象
    pthread_mutex_t &getMutex() { return lock_; }
#ifndef _WIN32
    // 尝试加锁,如果锁被占用则立即返回false
    virtual bool try_lock();
#endif

private:
#ifdef _WIN32
    // Windows平台使用临界区实现
    CRITICAL_SECTION m_critical_section;
#else
    // Unix/Linux平台使用pthread互斥锁实现
    pthread_mutex_t lock_;
#endif
};


#ifndef _WIN32
class CRWLock {
  public:
    CRWLock();
    virtual ~CRWLock();
    void rlock();
    void wlock();
    void unlock();
    bool try_rlock();
    bool try_wlock();

  private:
    pthread_rwlock_t lock_;
};

class CAutoRWLock {
  public:
    CAutoRWLock(CRWLock *pLock, bool bRLock = true);
    virtual ~CAutoRWLock();

  private:
    CRWLock *lock_;
};

#endif


class CAutoLock {
  public:
    CAutoLock(CLock *pLock);
    virtual ~CAutoLock();

  private:
    CLock *m_pLock;
};

#endif