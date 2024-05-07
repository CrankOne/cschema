#pragma once

#include "cschema-node.hh"

namespace xsc {

// object (string dictionary) node
class Object
    : public iNode
    , protected std::unordered_map<std::string, std::shared_ptr<iNode>>
    {
public:
    typedef std::unordered_map<std::string, std::shared_ptr<iNode>> Parent;

    using Parent::begin;
    using Parent::end;
    using Parent::insert;
    using Parent::emplace;
    
    Object() : iNode(iNode::kObject) {}

    iNode & operator[](const std::string & nm);
    const iNode & operator[](const std::string & nm) const;
};  // class iObject

}  // namespace xsc

