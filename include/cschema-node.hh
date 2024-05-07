#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

namespace xsc {

class iValidator;  // fwd

// base for schema node
class iNode : protected std::list<std::shared_ptr<iValidator>> {
public:
    enum NodeType { kNull = 0x0
        , kAbsCompound    = 0xf  // not used directly, a shortcut
        , kBoolean        = 0x1
        , kInteger        = 0x2
        , kFloat          = 0x3
        , kString         = 0x4
        , kUnion          = 0x5
        , kObject         = kAbsCompound | 0x1
        , kList           = kAbsCompound | 0x2
    };
private:
    NodeType _scalarType;
public:
    NodeType type() const { return _scalarType; }
    virtual ~iNode() {}
    template<typename T> T & as()
        { return const_cast<const iNode &>(*this).as<const T>(); }
    template<typename T> const T & as() const;
    bool validate(const iValidator &) const;
    std::list<std::shared_ptr<iValidator>> & validators() {return *this;}
    const std::list<std::shared_ptr<iValidator>> & validators() const {return *this;}
protected:
    iNode(NodeType nt) : _scalarType(nt) {}
    void type(NodeType nt) { _scalarType = nt; }
};  // class iNode

}  // namespace xsc

