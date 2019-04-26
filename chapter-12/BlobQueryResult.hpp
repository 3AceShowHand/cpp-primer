//
// Created by king on 2019/4/26.
//

#ifndef CPP_PRIMER_BLOBQUERYRESULT_HPP
#define CPP_PRIMER_BLOBQUERYRESULT_HPP

#include <string>
#include <memory>
#include <set>
#include "StrBlob.hpp"


class BlobQueryResult {
    using line_no_t = StrBlob::size_type;
    friend std::ostream& print(std::ostream& os, const BlobQueryResult& bqr);

public:
    BlobQueryResult(const std::string& s, std::shared_ptr<std::set<line_no_t>> p,
            const StrBlob& b): sought(s), positions(p), file(b) {

    }

    StrBlob get_file() {
        return file;
    }

    std::set<line_no_t>::iterator begin() {
        return positions->begin();
    }

    std::set<line_no_t>::iterator end() {
        return positions->end();
    }

    const std::set<line_no_t>::const_iterator cbegin() const {
        return positions->cbegin();
    }

    const std::set<line_no_t>::const_iterator cend() const {
        return positions->cend();
    }

private:
    std::string sought;
    std::shared_ptr<std::set<line_no_t>> positions;
    StrBlob file;

};

std::ostream& print(std::ostream& os, const BlobQueryResult& bqr);

#endif //CPP_PRIMER_BLOBQUERYRESULT_HPP
