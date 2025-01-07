#ifndef _SCOPE_PTR_HH
#define _SCOPE_PTR_HH
//  scoped_ptr mimics a built-in pointer except that it guarantees deletion
//  of the object pointed to, either on destruction of the scoped_ptr or via
//  an explicit reset(). scoped_ptr is a simple solution for simple needs;
//  use std::shared_ptr or std::unique_ptr if your needs are more complex.

/*
历史遗留代码：
scoped_ptr 是局部智能指针 不允许转让所有权。
*/

// ToDo: replace it with std::unique_ptr

template <class T> class scoped_ptr {
public:
    scoped_ptr(T *p = 0) : ptr_(p) {}
    ~scoped_ptr() { delete ptr_; }

    T& operator*() const {return *ptr_;}
    T* operator->() const {return ptr_;}

    void reset(T *p) {
        if (p != ptr_ && ptr_ != 0) {
            delete ptr_;
        }
        ptr_ = p;
    }

    T* get() const {return ptr_;}

    operator bool() const {return get() != NULL;}
private:
    T *ptr_;

    scoped_ptr(const scoped_ptr<T> &y);
    const scoped_ptr<T> operator=(const scoped_ptr<T> &);
    void operator==(scoped_ptr<T> const &) const;
    void operator!=(scoped_ptr<T> const &) const;
};


#endif