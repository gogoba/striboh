//
// Created by coder.peter.grobarcik@gmail.com on 7/24/20.
//

#include <iostream>
#include <stdexcept>

#include "stribohIdlAstModuleNode.hpp"
#include "stribohIdlAstModuleBodyNode.hpp"

namespace striboh {
    namespace idl {
        namespace ast {

            using std::cout;

            ModuleNode::ModuleNode(const IdentifierNode& pIdent)
                    : BaseValueNode<IdentifierNode>(K_MODULE_NODE, pIdent), mBody(new ModuleBodyNode()) {
                cout << "Creating module with identifier \"" << pIdent.getValue() << ".\"";
            }

            const std::string& ModuleNode::getIdentifierStr() const {
                return getValue().getValue();
            }

            const ModuleBodyNode& ModuleNode::getModuleBody() const {
                return *mBody;
            }

            ModuleBodyNode& ModuleNode::getModuleBody() {
                return *mBody;
            }

            void ModuleNode::addModuleBody(const ModuleBodyNode& pModuleBodyNode) {
                mBody.reset(new ModuleBodyNode(pModuleBodyNode));
            }

            ModuleNode::ModuleNode(const ModuleNode& pModuleNode) :
                    BaseValueNode<IdentifierNode>(K_MODULE_NODE, pModuleNode.getValue()),
                    mBody(new ModuleBodyNode(pModuleNode.getModuleBody())) {
            }

            ModuleNode& ModuleNode::operator=(const ModuleNode& pModuleNode) {
                setValue(pModuleNode.getValue());
                *mBody = *pModuleNode.mBody;
                return *this;
            }

            ModuleNode::ModuleNode()
                    : BaseValueNode<IdentifierNode>(K_MODULE_NODE), mBody(new ModuleBodyNode()) {
            }

            ModuleNode::~ModuleNode() = default;

            ModuleNode& operator+=(ModuleNode& pModuleNode, const ModuleBodyNode& pModuleBodyNode) {
                pModuleNode.addModuleBody(pModuleBodyNode);
            }

        }
    }
};