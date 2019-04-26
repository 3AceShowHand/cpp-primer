//
// Created by king on 2019/4/26.
//

#ifndef CPP_PRIMER_TEXTBLOBQUERY_HPP
#define CPP_PRIMER_TEXTBLOBQUERY_HPP

#include <set>
#include <map>
#include <memory>
#include "StrBlob.hpp"


class BlobQueryResult;
class TextBlobQuery {

    using line_no_t = StrBlob::size_type;

public:
    explicit TextBlobQuery(std::istream& infile);
    BlobQueryResult query(const std::string& sought) const;

private:
    StrBlob file;
    std::map<std::string, std::shared_ptr<std::set<line_no_t>>> records;
};

#endif //CPP_PRIMER_TEXTBLOBQUERY_HPP
