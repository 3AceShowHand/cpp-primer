//
// Created by king on 2019/4/25.
//

#ifndef CPP_PRIMER_CONSTSTRBLOBPTR_HPP
#define CPP_PRIMER_CONSTSTRBLOBPTR_HPP

#include <vector>
#include <string>
#include <memory>

class StrBlob;

class ConstStrBlobPtr {
    using size_type = std::vector<std::string>::size_type ;

public:
    ConstStrBlobPtr();
    explicit ConstStrBlobPtr(const StrBlob& sb, size_type pos = 0);

    const std::string& deref() const;

    ConstStrBlobPtr& incr();

    bool operator!=(const ConstStrBlobPtr& p);

private:
    std::weak_ptr<std::vector<std::string>> wptr;
    size_type curr;

    std::shared_ptr<std::vector<std::string>>
    check(size_type pos, const std::string &msg) const;
};

#endif //CPP_PRIMER_CONSTSTRBLOBPTR_HPP
