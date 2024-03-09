/**
 *
 *  Category.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Category.h"
#include "Blog.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::sqlite3;

const std::string Category::Cols::_id = "id";
const std::string Category::Cols::_name = "name";
const std::string Category::primaryKeyName = "id";
const bool Category::hasPrimaryKey = true;
const std::string Category::tableName = "category";

const std::vector<typename Category::MetaData> Category::metaData_ = {
    {"id", "int64_t", "integer auto_increment", 8, 0, 1, 0},
    {"name", "std::string", "varchar(30)", 0, 0, 0, 0}};

const std::string &Category::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}

Category::Category(const Row &r, const ssize_t indexOffset) noexcept
{
    if (indexOffset < 0)
    {
        if (!r["id"].isNull())
        {
            id_ = std::make_shared<int64_t>(r["id"].as<int64_t>());
        }
        if (!r["name"].isNull())
        {
            name_ = std::make_shared<std::string>(r["name"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if (offset + 2 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if (!r[index].isNull())
        {
            id_ = std::make_shared<int64_t>(r[index].as<int64_t>());
        }
        index = offset + 1;
        if (!r[index].isNull())
        {
            name_ = std::make_shared<std::string>(r[index].as<std::string>());
        }
    }
}

Category::Category(
    const Json::Value &pJson,
    const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if (pMasqueradingVector.size() != 2)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if (!pMasqueradingVector[0].empty() &&
        pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if (!pJson[pMasqueradingVector[0]].isNull())
        {
            id_ = std::make_shared<int64_t>(
                (int64_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if (!pMasqueradingVector[1].empty() &&
        pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if (!pJson[pMasqueradingVector[1]].isNull())
        {
            name_ = std::make_shared<std::string>(
                pJson[pMasqueradingVector[1]].asString());
        }
    }
}

Category::Category(const Json::Value &pJson) noexcept(false)
{
    if (pJson.isMember("id"))
    {
        dirtyFlag_[0] = true;
        if (!pJson["id"].isNull())
        {
            id_ = std::make_shared<int64_t>((int64_t)pJson["id"].asInt64());
        }
    }
    if (pJson.isMember("name"))
    {
        dirtyFlag_[1] = true;
        if (!pJson["name"].isNull())
        {
            name_ = std::make_shared<std::string>(pJson["name"].asString());
        }
    }
}

void Category::updateByMasqueradedJson(
    const Json::Value &pJson,
    const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if (pMasqueradingVector.size() != 2)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if (!pMasqueradingVector[0].empty() &&
        pJson.isMember(pMasqueradingVector[0]))
    {
        if (!pJson[pMasqueradingVector[0]].isNull())
        {
            id_ = std::make_shared<int64_t>(
                (int64_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if (!pMasqueradingVector[1].empty() &&
        pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if (!pJson[pMasqueradingVector[1]].isNull())
        {
            name_ = std::make_shared<std::string>(
                pJson[pMasqueradingVector[1]].asString());
        }
    }
}

void Category::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if (pJson.isMember("id"))
    {
        if (!pJson["id"].isNull())
        {
            id_ = std::make_shared<int64_t>((int64_t)pJson["id"].asInt64());
        }
    }
    if (pJson.isMember("name"))
    {
        dirtyFlag_[1] = true;
        if (!pJson["name"].isNull())
        {
            name_ = std::make_shared<std::string>(pJson["name"].asString());
        }
    }
}

const int64_t &Category::getValueOfId() const noexcept
{
    static const int64_t defaultValue = int64_t();
    if (id_)
        return *id_;
    return defaultValue;
}

const std::shared_ptr<int64_t> &Category::getId() const noexcept
{
    return id_;
}

void Category::setId(const int64_t &pId) noexcept
{
    id_ = std::make_shared<int64_t>(pId);
    dirtyFlag_[0] = true;
}

void Category::setIdToNull() noexcept
{
    id_.reset();
    dirtyFlag_[0] = true;
}

const typename Category::PrimaryKeyType &Category::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Category::getValueOfName() const noexcept
{
    static const std::string defaultValue = std::string();
    if (name_)
        return *name_;
    return defaultValue;
}

const std::shared_ptr<std::string> &Category::getName() const noexcept
{
    return name_;
}

void Category::setName(const std::string &pName) noexcept
{
    name_ = std::make_shared<std::string>(pName);
    dirtyFlag_[1] = true;
}

void Category::setName(std::string &&pName) noexcept
{
    name_ = std::make_shared<std::string>(std::move(pName));
    dirtyFlag_[1] = true;
}

void Category::setNameToNull() noexcept
{
    name_.reset();
    dirtyFlag_[1] = true;
}

void Category::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Category::insertColumns() noexcept
{
    static const std::vector<std::string> inCols = {"id", "name"};
    return inCols;
}

void Category::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if (dirtyFlag_[0])
    {
        if (getId())
        {
            binder << getValueOfId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if (dirtyFlag_[1])
    {
        if (getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Category::updateColumns() const
{
    std::vector<std::string> ret;
    if (dirtyFlag_[0])
    {
        ret.push_back(getColumnName(0));
    }
    if (dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    return ret;
}

void Category::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if (dirtyFlag_[0])
    {
        if (getId())
        {
            binder << getValueOfId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if (dirtyFlag_[1])
    {
        if (getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
}

Json::Value Category::toJson() const
{
    Json::Value ret;
    if (getId())
    {
        ret["id"] = (Json::Int64)getValueOfId();
    }
    else
    {
        ret["id"] = Json::Value();
    }
    if (getName())
    {
        ret["name"] = getValueOfName();
    }
    else
    {
        ret["name"] = Json::Value();
    }
    return ret;
}

Json::Value Category::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if (pMasqueradingVector.size() == 2)
    {
        if (!pMasqueradingVector[0].empty())
        {
            if (getId())
            {
                ret[pMasqueradingVector[0]] = (Json::Int64)getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]] = Json::Value();
            }
        }
        if (!pMasqueradingVector[1].empty())
        {
            if (getName())
            {
                ret[pMasqueradingVector[1]] = getValueOfName();
            }
            else
            {
                ret[pMasqueradingVector[1]] = Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if (getId())
    {
        ret["id"] = (Json::Int64)getValueOfId();
    }
    else
    {
        ret["id"] = Json::Value();
    }
    if (getName())
    {
        ret["name"] = getValueOfName();
    }
    else
    {
        ret["name"] = Json::Value();
    }
    return ret;
}

bool Category::validateJsonForCreation(const Json::Value &pJson,
                                       std::string &err)
{
    if (pJson.isMember("id"))
    {
        if (!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if (pJson.isMember("name"))
    {
        if (!validJsonOfField(1, "name", pJson["name"], err, true))
            return false;
    }
    return true;
}

bool Category::validateMasqueradedJsonForCreation(
    const Json::Value &pJson,
    const std::vector<std::string> &pMasqueradingVector,
    std::string &err)
{
    if (pMasqueradingVector.size() != 2)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try
    {
        if (!pMasqueradingVector[0].empty())
        {
            if (pJson.isMember(pMasqueradingVector[0]))
            {
                if (!validJsonOfField(0,
                                      pMasqueradingVector[0],
                                      pJson[pMasqueradingVector[0]],
                                      err,
                                      true))
                    return false;
            }
        }
        if (!pMasqueradingVector[1].empty())
        {
            if (pJson.isMember(pMasqueradingVector[1]))
            {
                if (!validJsonOfField(1,
                                      pMasqueradingVector[1],
                                      pJson[pMasqueradingVector[1]],
                                      err,
                                      true))
                    return false;
            }
        }
    }
    catch (const Json::LogicError &e)
    {
        err = e.what();
        return false;
    }
    return true;
}

bool Category::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if (pJson.isMember("id"))
    {
        if (!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err =
            "The value of primary key must be set in the json object for "
            "update";
        return false;
    }
    if (pJson.isMember("name"))
    {
        if (!validJsonOfField(1, "name", pJson["name"], err, false))
            return false;
    }
    return true;
}

bool Category::validateMasqueradedJsonForUpdate(
    const Json::Value &pJson,
    const std::vector<std::string> &pMasqueradingVector,
    std::string &err)
{
    if (pMasqueradingVector.size() != 2)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try
    {
        if (!pMasqueradingVector[0].empty() &&
            pJson.isMember(pMasqueradingVector[0]))
        {
            if (!validJsonOfField(0,
                                  pMasqueradingVector[0],
                                  pJson[pMasqueradingVector[0]],
                                  err,
                                  false))
                return false;
        }
        else
        {
            err =
                "The value of primary key must be set in the json object for "
                "update";
            return false;
        }
        if (!pMasqueradingVector[1].empty() &&
            pJson.isMember(pMasqueradingVector[1]))
        {
            if (!validJsonOfField(1,
                                  pMasqueradingVector[1],
                                  pJson[pMasqueradingVector[1]],
                                  err,
                                  false))
                return false;
        }
    }
    catch (const Json::LogicError &e)
    {
        err = e.what();
        return false;
    }
    return true;
}

bool Category::validJsonOfField(size_t index,
                                const std::string &fieldName,
                                const Json::Value &pJson,
                                std::string &err,
                                bool isForCreation)
{
    switch (index)
    {
        case 0:
            if (pJson.isNull())
            {
                return true;
            }
            if (!pJson.isInt64())
            {
                err = "Type error in the " + fieldName + " field";
                return false;
            }
            break;
        case 1:
            if (pJson.isNull())
            {
                return true;
            }
            if (!pJson.isString())
            {
                err = "Type error in the " + fieldName + " field";
                return false;
            }
            break;
        default:
            err = "Internal error in the server";
            return false;
    }
    return true;
}

std::vector<Blog> Category::getBlogs(const DbClientPtr &clientPtr) const
{
    static const std::string sql = "select * from blog where category_id = ?";
    Result r(nullptr);
    {
        auto binder = *clientPtr << sql;
        binder << *id_ << Mode::Blocking >>
            [&r](const Result &result) { r = result; };
        binder.exec();
    }
    std::vector<Blog> ret;
    ret.reserve(r.size());
    for (auto const &row : r)
    {
        ret.emplace_back(Blog(row));
    }
    return ret;
}

void Category::getBlogs(const DbClientPtr &clientPtr,
                        const std::function<void(std::vector<Blog>)> &rcb,
                        const ExceptionCallback &ecb) const
{
    static const std::string sql = "select * from blog where category_id = ?";
    *clientPtr << sql << *id_ >> [rcb = std::move(rcb)](const Result &r) {
        std::vector<Blog> ret;
        ret.reserve(r.size());
        for (auto const &row : r)
        {
            ret.emplace_back(Blog(row));
        }
        rcb(ret);
    } >> ecb;
}
