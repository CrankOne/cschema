#pragma once

#include "cschema-node.hh"

namespace xsc {

// union (one-of) node
class Union
    : public iNode
    , protected std::vector<std::shared_ptr<iNode>>
    {
public:
    Union() : iNode(iNode::kUnion) {}
};  // class Union

}  // namespace xsc

