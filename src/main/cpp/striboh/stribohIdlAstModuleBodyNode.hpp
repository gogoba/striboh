//
// Created by grobap on 8/2/20.
//

#ifndef STRIBOH_STRIBOHIDLASTMODULEBODYNODE_HPP
#define STRIBOH_STRIBOHIDLASTMODULEBODYNODE_HPP


#include "stribohIdlAstBaseNode.hpp"
#include "stribohIdlAstModuleListNode.hpp"
#include "stribohIdlAstInterfaceListNode.hpp"

namespace striboh {
    namespace idl {
        namespace ast {
            constexpr const char *const K_MODULE_BODY_NODE = "ModuleBodyNode";

            struct ModuleBodyNode : public BaseTupleNode<ModuleListNode, InterfaceListNode> {

                ModuleBodyNode() :
                        BaseTupleNode<ModuleListNode, InterfaceListNode>(K_MODULE_BODY_NODE) {}

                ModuleBodyNode(const ModuleBodyNode& pModuleBody) :
                        BaseTupleNode<ModuleListNode, InterfaceListNode>(K_MODULE_BODY_NODE, pModuleBody) {}

                ModuleBodyNode(const ModuleListNode& pModuleList) :
                        BaseTupleNode<ModuleListNode, InterfaceListNode>(K_MODULE_BODY_NODE, pModuleList) {
                }

                ModuleBodyNode(ModuleListNode&& pModuleList) :
                        BaseTupleNode<ModuleListNode, InterfaceListNode>(K_MODULE_BODY_NODE, pModuleList) {
                }

                ModuleBodyNode& operator=(const ModuleListNode& pModuleList) {
                    getSubNode1() = pModuleList;
                    return *this;
                }

                ModuleBodyNode& operator=(ModuleListNode&& pModuleList) {
                    getSubNode1() = pModuleList;
                    return *this;
                }

                ModuleBodyNode& operator=(ModuleBodyNode&& pModuleBody) {
                    type_t::operator=(pModuleBody);
                    return *this;
                }

                ModuleBodyNode& operator=(const ModuleBodyNode& pModuleBody) {
                    type_t::operator=(pModuleBody);
                    return *this;
                }

                const ModuleListNode& getNodules() const {
                    return getSubNode1();
                }
            };

        }
    }
}


#endif //STRIBOH_STRIBOHIDLASTMODULEBODYNODE_HPP