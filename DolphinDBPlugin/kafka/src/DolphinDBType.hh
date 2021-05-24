/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef DOLPHINDBTYPE_HH_4246870673__H_
#define DOLPHINDBTYPE_HH_4246870673__H_


#include <sstream>
#include "boost/any.hpp"
#include "avro/Specific.hh"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"

namespace kafkaImp {
struct DolphinDBType_json_Union__0__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    bool get_bool() const;
    void set_bool(const bool& v);
    int32_t get_int() const;
    void set_int(const int32_t& v);
    int64_t get_long() const;
    void set_long(const int64_t& v);
    float get_float() const;
    void set_float(const float& v);
    double get_double() const;
    void set_double(const double& v);
    std::string get_string() const;
    void set_string(const std::string& v);
    DolphinDBType_json_Union__0__();
};

struct AvroScalar {
    typedef DolphinDBType_json_Union__0__ intern_t;
    intern_t intern;
    AvroScalar() :
        intern(intern_t())
        { }
};

struct AvroScalar;
struct AvroVector;
struct AvroTable;
struct AvroDictionary;
struct DolphinDBType_json_Union__1__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    AvroScalar get_AvroScalar() const;
    void set_AvroScalar(const AvroScalar& v);
    AvroVector get_AvroVector() const;
    void set_AvroVector(const AvroVector& v);
    AvroTable get_AvroTable() const;
    void set_AvroTable(const AvroTable& v);
    AvroDictionary get_AvroDictionary() const;
    void set_AvroDictionary(const AvroDictionary& v);
    DolphinDBType_json_Union__1__();
};

struct AvroVector {
    std::vector<DolphinDBType_json_Union__1__ > intern;
    AvroVector() :
        intern(std::vector<DolphinDBType_json_Union__1__ >())
        { }
};

struct DolphinDBType_json_Union__2__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    bool get_bool() const;
    void set_bool(const bool& v);
    DolphinDBType_json_Union__2__();
};

struct cbool {
    std::vector<DolphinDBType_json_Union__2__ > intern;
    cbool() :
        intern(std::vector<DolphinDBType_json_Union__2__ >())
        { }
};

struct DolphinDBType_json_Union__3__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    int32_t get_int() const;
    void set_int(const int32_t& v);
    DolphinDBType_json_Union__3__();
};

struct cint {
    std::vector<DolphinDBType_json_Union__3__ > intern;
    cint() :
        intern(std::vector<DolphinDBType_json_Union__3__ >())
        { }
};

struct DolphinDBType_json_Union__4__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    int64_t get_long() const;
    void set_long(const int64_t& v);
    DolphinDBType_json_Union__4__();
};

struct clong {
    std::vector<DolphinDBType_json_Union__4__ > intern;
    clong() :
        intern(std::vector<DolphinDBType_json_Union__4__ >())
        { }
};

struct DolphinDBType_json_Union__5__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    float get_float() const;
    void set_float(const float& v);
    DolphinDBType_json_Union__5__();
};

struct cfloat {
    std::vector<DolphinDBType_json_Union__5__ > intern;
    cfloat() :
        intern(std::vector<DolphinDBType_json_Union__5__ >())
        { }
};

struct DolphinDBType_json_Union__6__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    double get_double() const;
    void set_double(const double& v);
    DolphinDBType_json_Union__6__();
};

struct cdouble {
    std::vector<DolphinDBType_json_Union__6__ > intern;
    cdouble() :
        intern(std::vector<DolphinDBType_json_Union__6__ >())
        { }
};

struct DolphinDBType_json_Union__7__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    bool is_null() const {
        return (idx_ == 0);
    }
    void set_null() {
        idx_ = 0;
        value_ = boost::any();
    }
    std::string get_string() const;
    void set_string(const std::string& v);
    DolphinDBType_json_Union__7__();
};

struct cstring {
    std::vector<DolphinDBType_json_Union__7__ > intern;
    cstring() :
        intern(std::vector<DolphinDBType_json_Union__7__ >())
        { }
};

struct DolphinDBType_json_Union__8__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    cbool get_cbool() const;
    void set_cbool(const cbool& v);
    cint get_cint() const;
    void set_cint(const cint& v);
    clong get_clong() const;
    void set_clong(const clong& v);
    cfloat get_cfloat() const;
    void set_cfloat(const cfloat& v);
    cdouble get_cdouble() const;
    void set_cdouble(const cdouble& v);
    cstring get_cstring() const;
    void set_cstring(const cstring& v);
    DolphinDBType_json_Union__8__();
};

struct AvroTable {
    std::vector<DolphinDBType_json_Union__8__ > intern;
    AvroTable() :
        intern(std::vector<DolphinDBType_json_Union__8__ >())
        { }
};

struct AvroScalar;
struct AvroVector;
struct AvroTable;
struct AvroDictionary;
struct DolphinDBType_json_Union__9__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    AvroScalar get_AvroScalar() const;
    void set_AvroScalar(const AvroScalar& v);
    AvroVector get_AvroVector() const;
    void set_AvroVector(const AvroVector& v);
    AvroTable get_AvroTable() const;
    void set_AvroTable(const AvroTable& v);
    AvroDictionary get_AvroDictionary() const;
    void set_AvroDictionary(const AvroDictionary& v);
    DolphinDBType_json_Union__9__();
};

struct AvroDictionary {
    std::map<std::string, DolphinDBType_json_Union__9__ > intern;
    AvroDictionary() :
        intern(std::map<std::string, DolphinDBType_json_Union__9__ >())
        { }
};

struct DolphinDBType_json_Union__10__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    AvroScalar get_AvroScalar() const;
    void set_AvroScalar(const AvroScalar& v);
    AvroVector get_AvroVector() const;
    void set_AvroVector(const AvroVector& v);
    AvroTable get_AvroTable() const;
    void set_AvroTable(const AvroTable& v);
    AvroDictionary get_AvroDictionary() const;
    void set_AvroDictionary(const AvroDictionary& v);
    DolphinDBType_json_Union__10__();
};

struct DolphinDBType_json_Union__11__ {
private:
    size_t idx_;
    boost::any value_;
public:
    size_t idx() const { return idx_; }
    AvroScalar get_AvroScalar() const;
    void set_AvroScalar(const AvroScalar& v);
    AvroVector get_AvroVector() const;
    void set_AvroVector(const AvroVector& v);
    AvroTable get_AvroTable() const;
    void set_AvroTable(const AvroTable& v);
    AvroDictionary get_AvroDictionary() const;
    void set_AvroDictionary(const AvroDictionary& v);
    DolphinDBType_json_Union__11__();
};

inline
bool DolphinDBType_json_Union__0__::get_bool() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<bool >(value_);
}

inline
void DolphinDBType_json_Union__0__::set_bool(const bool& v) {
    idx_ = 1;
    value_ = v;
}

inline
int32_t DolphinDBType_json_Union__0__::get_int() const {
    if (idx_ != 2) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<int32_t >(value_);
}

inline
void DolphinDBType_json_Union__0__::set_int(const int32_t& v) {
    idx_ = 2;
    value_ = v;
}

inline
int64_t DolphinDBType_json_Union__0__::get_long() const {
    if (idx_ != 3) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<int64_t >(value_);
}

inline
void DolphinDBType_json_Union__0__::set_long(const int64_t& v) {
    idx_ = 3;
    value_ = v;
}

inline
float DolphinDBType_json_Union__0__::get_float() const {
    if (idx_ != 4) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<float >(value_);
}

inline
void DolphinDBType_json_Union__0__::set_float(const float& v) {
    idx_ = 4;
    value_ = v;
}

inline
double DolphinDBType_json_Union__0__::get_double() const {
    if (idx_ != 5) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<double >(value_);
}

inline
void DolphinDBType_json_Union__0__::set_double(const double& v) {
    idx_ = 5;
    value_ = v;
}

inline
std::string DolphinDBType_json_Union__0__::get_string() const {
    if (idx_ != 6) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<std::string >(value_);
}

inline
void DolphinDBType_json_Union__0__::set_string(const std::string& v) {
    idx_ = 6;
    value_ = v;
}

inline
AvroScalar DolphinDBType_json_Union__1__::get_AvroScalar() const {
    if (idx_ != 0) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroScalar >(value_);
}

inline
void DolphinDBType_json_Union__1__::set_AvroScalar(const AvroScalar& v) {
    idx_ = 0;
    value_ = v;
}

inline
AvroVector DolphinDBType_json_Union__1__::get_AvroVector() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroVector >(value_);
}

inline
void DolphinDBType_json_Union__1__::set_AvroVector(const AvroVector& v) {
    idx_ = 1;
    value_ = v;
}

inline
AvroTable DolphinDBType_json_Union__1__::get_AvroTable() const {
    if (idx_ != 2) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroTable >(value_);
}

inline
void DolphinDBType_json_Union__1__::set_AvroTable(const AvroTable& v) {
    idx_ = 2;
    value_ = v;
}

inline
AvroDictionary DolphinDBType_json_Union__1__::get_AvroDictionary() const {
    if (idx_ != 3) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroDictionary >(value_);
}

inline
void DolphinDBType_json_Union__1__::set_AvroDictionary(const AvroDictionary& v) {
    idx_ = 3;
    value_ = v;
}

inline
bool DolphinDBType_json_Union__2__::get_bool() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<bool >(value_);
}

inline
void DolphinDBType_json_Union__2__::set_bool(const bool& v) {
    idx_ = 1;
    value_ = v;
}

inline
int32_t DolphinDBType_json_Union__3__::get_int() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<int32_t >(value_);
}

inline
void DolphinDBType_json_Union__3__::set_int(const int32_t& v) {
    idx_ = 1;
    value_ = v;
}

inline
int64_t DolphinDBType_json_Union__4__::get_long() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<int64_t >(value_);
}

inline
void DolphinDBType_json_Union__4__::set_long(const int64_t& v) {
    idx_ = 1;
    value_ = v;
}

inline
float DolphinDBType_json_Union__5__::get_float() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<float >(value_);
}

inline
void DolphinDBType_json_Union__5__::set_float(const float& v) {
    idx_ = 1;
    value_ = v;
}

inline
double DolphinDBType_json_Union__6__::get_double() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<double >(value_);
}

inline
void DolphinDBType_json_Union__6__::set_double(const double& v) {
    idx_ = 1;
    value_ = v;
}

inline
std::string DolphinDBType_json_Union__7__::get_string() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<std::string >(value_);
}

inline
void DolphinDBType_json_Union__7__::set_string(const std::string& v) {
    idx_ = 1;
    value_ = v;
}

inline
cbool DolphinDBType_json_Union__8__::get_cbool() const {
    if (idx_ != 0) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<cbool >(value_);
}

inline
void DolphinDBType_json_Union__8__::set_cbool(const cbool& v) {
    idx_ = 0;
    value_ = v;
}

inline
cint DolphinDBType_json_Union__8__::get_cint() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<cint >(value_);
}

inline
void DolphinDBType_json_Union__8__::set_cint(const cint& v) {
    idx_ = 1;
    value_ = v;
}

inline
clong DolphinDBType_json_Union__8__::get_clong() const {
    if (idx_ != 2) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<clong >(value_);
}

inline
void DolphinDBType_json_Union__8__::set_clong(const clong& v) {
    idx_ = 2;
    value_ = v;
}

inline
cfloat DolphinDBType_json_Union__8__::get_cfloat() const {
    if (idx_ != 3) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<cfloat >(value_);
}

inline
void DolphinDBType_json_Union__8__::set_cfloat(const cfloat& v) {
    idx_ = 3;
    value_ = v;
}

inline
cdouble DolphinDBType_json_Union__8__::get_cdouble() const {
    if (idx_ != 4) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<cdouble >(value_);
}

inline
void DolphinDBType_json_Union__8__::set_cdouble(const cdouble& v) {
    idx_ = 4;
    value_ = v;
}

inline
cstring DolphinDBType_json_Union__8__::get_cstring() const {
    if (idx_ != 5) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<cstring >(value_);
}

inline
void DolphinDBType_json_Union__8__::set_cstring(const cstring& v) {
    idx_ = 5;
    value_ = v;
}

inline
AvroScalar DolphinDBType_json_Union__9__::get_AvroScalar() const {
    if (idx_ != 0) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroScalar >(value_);
}

inline
void DolphinDBType_json_Union__9__::set_AvroScalar(const AvroScalar& v) {
    idx_ = 0;
    value_ = v;
}

inline
AvroVector DolphinDBType_json_Union__9__::get_AvroVector() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroVector >(value_);
}

inline
void DolphinDBType_json_Union__9__::set_AvroVector(const AvroVector& v) {
    idx_ = 1;
    value_ = v;
}

inline
AvroTable DolphinDBType_json_Union__9__::get_AvroTable() const {
    if (idx_ != 2) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroTable >(value_);
}

inline
void DolphinDBType_json_Union__9__::set_AvroTable(const AvroTable& v) {
    idx_ = 2;
    value_ = v;
}

inline
AvroDictionary DolphinDBType_json_Union__9__::get_AvroDictionary() const {
    if (idx_ != 3) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroDictionary >(value_);
}

inline
void DolphinDBType_json_Union__9__::set_AvroDictionary(const AvroDictionary& v) {
    idx_ = 3;
    value_ = v;
}

inline
AvroScalar DolphinDBType_json_Union__10__::get_AvroScalar() const {
    if (idx_ != 0) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroScalar >(value_);
}

inline
void DolphinDBType_json_Union__10__::set_AvroScalar(const AvroScalar& v) {
    idx_ = 0;
    value_ = v;
}

inline
AvroVector DolphinDBType_json_Union__10__::get_AvroVector() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroVector >(value_);
}

inline
void DolphinDBType_json_Union__10__::set_AvroVector(const AvroVector& v) {
    idx_ = 1;
    value_ = v;
}

inline
AvroTable DolphinDBType_json_Union__10__::get_AvroTable() const {
    if (idx_ != 2) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroTable >(value_);
}

inline
void DolphinDBType_json_Union__10__::set_AvroTable(const AvroTable& v) {
    idx_ = 2;
    value_ = v;
}

inline
AvroDictionary DolphinDBType_json_Union__10__::get_AvroDictionary() const {
    if (idx_ != 3) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroDictionary >(value_);
}

inline
void DolphinDBType_json_Union__10__::set_AvroDictionary(const AvroDictionary& v) {
    idx_ = 3;
    value_ = v;
}

inline
AvroScalar DolphinDBType_json_Union__11__::get_AvroScalar() const {
    if (idx_ != 0) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroScalar >(value_);
}

inline
void DolphinDBType_json_Union__11__::set_AvroScalar(const AvroScalar& v) {
    idx_ = 0;
    value_ = v;
}

inline
AvroVector DolphinDBType_json_Union__11__::get_AvroVector() const {
    if (idx_ != 1) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroVector >(value_);
}

inline
void DolphinDBType_json_Union__11__::set_AvroVector(const AvroVector& v) {
    idx_ = 1;
    value_ = v;
}

inline
AvroTable DolphinDBType_json_Union__11__::get_AvroTable() const {
    if (idx_ != 2) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroTable >(value_);
}

inline
void DolphinDBType_json_Union__11__::set_AvroTable(const AvroTable& v) {
    idx_ = 2;
    value_ = v;
}

inline
AvroDictionary DolphinDBType_json_Union__11__::get_AvroDictionary() const {
    if (idx_ != 3) {
        throw avro::Exception("Invalid type for union");
    }
    return boost::any_cast<AvroDictionary >(value_);
}

inline
void DolphinDBType_json_Union__11__::set_AvroDictionary(const AvroDictionary& v) {
    idx_ = 3;
    value_ = v;
}

inline DolphinDBType_json_Union__0__::DolphinDBType_json_Union__0__() : idx_(0) { }
inline DolphinDBType_json_Union__1__::DolphinDBType_json_Union__1__() : idx_(0), value_(AvroScalar()) { }
inline DolphinDBType_json_Union__2__::DolphinDBType_json_Union__2__() : idx_(0) { }
inline DolphinDBType_json_Union__3__::DolphinDBType_json_Union__3__() : idx_(0) { }
inline DolphinDBType_json_Union__4__::DolphinDBType_json_Union__4__() : idx_(0) { }
inline DolphinDBType_json_Union__5__::DolphinDBType_json_Union__5__() : idx_(0) { }
inline DolphinDBType_json_Union__6__::DolphinDBType_json_Union__6__() : idx_(0) { }
inline DolphinDBType_json_Union__7__::DolphinDBType_json_Union__7__() : idx_(0) { }
inline DolphinDBType_json_Union__8__::DolphinDBType_json_Union__8__() : idx_(0), value_(cbool()) { }
inline DolphinDBType_json_Union__9__::DolphinDBType_json_Union__9__() : idx_(0), value_(AvroScalar()) { }
inline DolphinDBType_json_Union__10__::DolphinDBType_json_Union__10__() : idx_(0), value_(AvroScalar()) { }
inline DolphinDBType_json_Union__11__::DolphinDBType_json_Union__11__() : idx_(0), value_(AvroScalar()) { }
}
namespace avro {
template<> struct codec_traits<kafkaImp::DolphinDBType_json_Union__0__> {
    static void encode(Encoder& e, kafkaImp::DolphinDBType_json_Union__0__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_bool());
            break;
        case 2:
            avro::encode(e, v.get_int());
            break;
        case 3:
            avro::encode(e, v.get_long());
            break;
        case 4:
            avro::encode(e, v.get_float());
            break;
        case 5:
            avro::encode(e, v.get_double());
            break;
        case 6:
            avro::encode(e, v.get_string());
            break;
        }
    }
    static void decode(Decoder& d, kafkaImp::DolphinDBType_json_Union__0__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 7) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                bool vv;
                avro::decode(d, vv);
                v.set_bool(vv);
            }
            break;
        case 2:
            {
                int32_t vv;
                avro::decode(d, vv);
                v.set_int(vv);
            }
            break;
        case 3:
            {
                int64_t vv;
                avro::decode(d, vv);
                v.set_long(vv);
            }
            break;
        case 4:
            {
                float vv;
                avro::decode(d, vv);
                v.set_float(vv);
            }
            break;
        case 5:
            {
                double vv;
                avro::decode(d, vv);
                v.set_double(vv);
            }
            break;
        case 6:
            {
                std::string vv;
                avro::decode(d, vv);
                v.set_string(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<kafkaImp::AvroScalar> {
    static void encode(Encoder& e, const kafkaImp::AvroScalar& v) {
        avro::encode(e, v.intern);
    }
    static void decode(Decoder& d, kafkaImp::AvroScalar& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.intern);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.intern);
        }
    }
};

template<> struct codec_traits<kafkaImp::DolphinDBType_json_Union__1__> {
    static void encode(Encoder& e, kafkaImp::DolphinDBType_json_Union__1__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            avro::encode(e, v.get_AvroScalar());
            break;
        case 1:
            avro::encode(e, v.get_AvroVector());
            break;
        case 2:
            avro::encode(e, v.get_AvroTable());
            break;
        case 3:
            avro::encode(e, v.get_AvroDictionary());
            break;
        }
    }
    static void decode(Decoder& d, kafkaImp::DolphinDBType_json_Union__1__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 4) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            {
                kafkaImp::AvroScalar vv;
                avro::decode(d, vv);
                v.set_AvroScalar(vv);
            }
            break;
        case 1:
            {
                kafkaImp::AvroVector vv;
                avro::decode(d, vv);
                v.set_AvroVector(vv);
            }
            break;
        case 2:
            {
                kafkaImp::AvroTable vv;
                avro::decode(d, vv);
                v.set_AvroTable(vv);
            }
            break;
        case 3:
            {
                kafkaImp::AvroDictionary vv;
                avro::decode(d, vv);
                v.set_AvroDictionary(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<kafkaImp::DolphinDBType_json_Union__2__> {
    static void encode(Encoder& e, kafkaImp::DolphinDBType_json_Union__2__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_bool());
            break;
        }
    }
    static void decode(Decoder& d, kafkaImp::DolphinDBType_json_Union__2__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                bool vv;
                avro::decode(d, vv);
                v.set_bool(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<kafkaImp::cbool> {
    static void encode(Encoder& e, const kafkaImp::cbool& v) {
        avro::encode(e, v.intern);
    }
    static void decode(Decoder& d, kafkaImp::cbool& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.intern);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.intern);
        }
    }
};

template<> struct codec_traits<kafkaImp::DolphinDBType_json_Union__3__> {
    static void encode(Encoder& e, kafkaImp::DolphinDBType_json_Union__3__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_int());
            break;
        }
    }
    static void decode(Decoder& d, kafkaImp::DolphinDBType_json_Union__3__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                int32_t vv;
                avro::decode(d, vv);
                v.set_int(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<kafkaImp::cint> {
    static void encode(Encoder& e, const kafkaImp::cint& v) {
        avro::encode(e, v.intern);
    }
    static void decode(Decoder& d, kafkaImp::cint& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.intern);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.intern);
        }
    }
};

template<> struct codec_traits<kafkaImp::DolphinDBType_json_Union__4__> {
    static void encode(Encoder& e, kafkaImp::DolphinDBType_json_Union__4__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_long());
            break;
        }
    }
    static void decode(Decoder& d, kafkaImp::DolphinDBType_json_Union__4__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                int64_t vv;
                avro::decode(d, vv);
                v.set_long(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<kafkaImp::clong> {
    static void encode(Encoder& e, const kafkaImp::clong& v) {
        avro::encode(e, v.intern);
    }
    static void decode(Decoder& d, kafkaImp::clong& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.intern);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.intern);
        }
    }
};

template<> struct codec_traits<kafkaImp::DolphinDBType_json_Union__5__> {
    static void encode(Encoder& e, kafkaImp::DolphinDBType_json_Union__5__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_float());
            break;
        }
    }
    static void decode(Decoder& d, kafkaImp::DolphinDBType_json_Union__5__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                float vv;
                avro::decode(d, vv);
                v.set_float(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<kafkaImp::cfloat> {
    static void encode(Encoder& e, const kafkaImp::cfloat& v) {
        avro::encode(e, v.intern);
    }
    static void decode(Decoder& d, kafkaImp::cfloat& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.intern);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.intern);
        }
    }
};

template<> struct codec_traits<kafkaImp::DolphinDBType_json_Union__6__> {
    static void encode(Encoder& e, kafkaImp::DolphinDBType_json_Union__6__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_double());
            break;
        }
    }
    static void decode(Decoder& d, kafkaImp::DolphinDBType_json_Union__6__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                double vv;
                avro::decode(d, vv);
                v.set_double(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<kafkaImp::cdouble> {
    static void encode(Encoder& e, const kafkaImp::cdouble& v) {
        avro::encode(e, v.intern);
    }
    static void decode(Decoder& d, kafkaImp::cdouble& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.intern);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.intern);
        }
    }
};

template<> struct codec_traits<kafkaImp::DolphinDBType_json_Union__7__> {
    static void encode(Encoder& e, kafkaImp::DolphinDBType_json_Union__7__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            e.encodeNull();
            break;
        case 1:
            avro::encode(e, v.get_string());
            break;
        }
    }
    static void decode(Decoder& d, kafkaImp::DolphinDBType_json_Union__7__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 2) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            d.decodeNull();
            v.set_null();
            break;
        case 1:
            {
                std::string vv;
                avro::decode(d, vv);
                v.set_string(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<kafkaImp::cstring> {
    static void encode(Encoder& e, const kafkaImp::cstring& v) {
        avro::encode(e, v.intern);
    }
    static void decode(Decoder& d, kafkaImp::cstring& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.intern);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.intern);
        }
    }
};

template<> struct codec_traits<kafkaImp::DolphinDBType_json_Union__8__> {
    static void encode(Encoder& e, kafkaImp::DolphinDBType_json_Union__8__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            avro::encode(e, v.get_cbool());
            break;
        case 1:
            avro::encode(e, v.get_cint());
            break;
        case 2:
            avro::encode(e, v.get_clong());
            break;
        case 3:
            avro::encode(e, v.get_cfloat());
            break;
        case 4:
            avro::encode(e, v.get_cdouble());
            break;
        case 5:
            avro::encode(e, v.get_cstring());
            break;
        }
    }
    static void decode(Decoder& d, kafkaImp::DolphinDBType_json_Union__8__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 6) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            {
                kafkaImp::cbool vv;
                avro::decode(d, vv);
                v.set_cbool(vv);
            }
            break;
        case 1:
            {
                kafkaImp::cint vv;
                avro::decode(d, vv);
                v.set_cint(vv);
            }
            break;
        case 2:
            {
                kafkaImp::clong vv;
                avro::decode(d, vv);
                v.set_clong(vv);
            }
            break;
        case 3:
            {
                kafkaImp::cfloat vv;
                avro::decode(d, vv);
                v.set_cfloat(vv);
            }
            break;
        case 4:
            {
                kafkaImp::cdouble vv;
                avro::decode(d, vv);
                v.set_cdouble(vv);
            }
            break;
        case 5:
            {
                kafkaImp::cstring vv;
                avro::decode(d, vv);
                v.set_cstring(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<kafkaImp::AvroTable> {
    static void encode(Encoder& e, const kafkaImp::AvroTable& v) {
        avro::encode(e, v.intern);
    }
    static void decode(Decoder& d, kafkaImp::AvroTable& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.intern);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.intern);
        }
    }
};

template<> struct codec_traits<kafkaImp::DolphinDBType_json_Union__9__> {
    static void encode(Encoder& e, kafkaImp::DolphinDBType_json_Union__9__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            avro::encode(e, v.get_AvroScalar());
            break;
        case 1:
            avro::encode(e, v.get_AvroVector());
            break;
        case 2:
            avro::encode(e, v.get_AvroTable());
            break;
        case 3:
            avro::encode(e, v.get_AvroDictionary());
            break;
        }
    }
    static void decode(Decoder& d, kafkaImp::DolphinDBType_json_Union__9__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 4) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            {
                kafkaImp::AvroScalar vv;
                avro::decode(d, vv);
                v.set_AvroScalar(vv);
            }
            break;
        case 1:
            {
                kafkaImp::AvroVector vv;
                avro::decode(d, vv);
                v.set_AvroVector(vv);
            }
            break;
        case 2:
            {
                kafkaImp::AvroTable vv;
                avro::decode(d, vv);
                v.set_AvroTable(vv);
            }
            break;
        case 3:
            {
                kafkaImp::AvroDictionary vv;
                avro::decode(d, vv);
                v.set_AvroDictionary(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<kafkaImp::DolphinDBType_json_Union__10__> {
    static void encode(Encoder& e, kafkaImp::DolphinDBType_json_Union__10__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            avro::encode(e, v.get_AvroScalar());
            break;
        case 1:
            avro::encode(e, v.get_AvroVector());
            break;
        case 2:
            avro::encode(e, v.get_AvroTable());
            break;
        case 3:
            avro::encode(e, v.get_AvroDictionary());
            break;
        }
    }
    static void decode(Decoder& d, kafkaImp::DolphinDBType_json_Union__10__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 4) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            {
                kafkaImp::AvroScalar vv;
                avro::decode(d, vv);
                v.set_AvroScalar(vv);
            }
            break;
        case 1:
            {
                kafkaImp::AvroVector vv;
                avro::decode(d, vv);
                v.set_AvroVector(vv);
            }
            break;
        case 2:
            {
                kafkaImp::AvroTable vv;
                avro::decode(d, vv);
                v.set_AvroTable(vv);
            }
            break;
        case 3:
            {
                kafkaImp::AvroDictionary vv;
                avro::decode(d, vv);
                v.set_AvroDictionary(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<kafkaImp::AvroDictionary> {
    static void encode(Encoder& e, const kafkaImp::AvroDictionary& v) {
        avro::encode(e, v.intern);
    }
    static void decode(Decoder& d, kafkaImp::AvroDictionary& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.intern);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.intern);
        }
    }
};

template<> struct codec_traits<kafkaImp::DolphinDBType_json_Union__11__> {
    static void encode(Encoder& e, kafkaImp::DolphinDBType_json_Union__11__ v) {
        e.encodeUnionIndex(v.idx());
        switch (v.idx()) {
        case 0:
            avro::encode(e, v.get_AvroScalar());
            break;
        case 1:
            avro::encode(e, v.get_AvroVector());
            break;
        case 2:
            avro::encode(e, v.get_AvroTable());
            break;
        case 3:
            avro::encode(e, v.get_AvroDictionary());
            break;
        }
    }
    static void decode(Decoder& d, kafkaImp::DolphinDBType_json_Union__11__& v) {
        size_t n = d.decodeUnionIndex();
        if (n >= 4) { throw avro::Exception("Union index too big"); }
        switch (n) {
        case 0:
            {
                kafkaImp::AvroScalar vv;
                avro::decode(d, vv);
                v.set_AvroScalar(vv);
            }
            break;
        case 1:
            {
                kafkaImp::AvroVector vv;
                avro::decode(d, vv);
                v.set_AvroVector(vv);
            }
            break;
        case 2:
            {
                kafkaImp::AvroTable vv;
                avro::decode(d, vv);
                v.set_AvroTable(vv);
            }
            break;
        case 3:
            {
                kafkaImp::AvroDictionary vv;
                avro::decode(d, vv);
                v.set_AvroDictionary(vv);
            }
            break;
        }
    }
};

template<> struct codec_traits<kafkaImp::AvroVector> {
    static void encode(Encoder& e, const kafkaImp::AvroVector& v) {
        avro::encode(e, v.intern);
    }
    static void decode(Decoder& d, kafkaImp::AvroVector& v) {
        if (avro::ResolvingDecoder *rd =
            dynamic_cast<avro::ResolvingDecoder *>(&d)) {
            const std::vector<size_t> fo = rd->fieldOrder();
            for (std::vector<size_t>::const_iterator it = fo.begin();
                it != fo.end(); ++it) {
                switch (*it) {
                case 0:
                    avro::decode(d, v.intern);
                    break;
                default:
                    break;
                }
            }
        } else {
            avro::decode(d, v.intern);
        }
    }
};

}
#endif
