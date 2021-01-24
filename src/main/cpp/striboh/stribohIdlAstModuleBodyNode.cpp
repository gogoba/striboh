//
// Created by grobap on 8/2/20.
//

#include "stribohIdlAstModuleNode.hpp"
#include "stribohIdlAstModuleBodyNode.hpp"

namespace striboh {
    namespace idl {
        namespace ast {

            ModuleNode& operator+=(ModuleNode& pModule, const ModuleBodyNode& pModBody) {
                BOOST_LOG_TRIVIAL(trace) << "Adding body to module " << pModBody.getValueStr();
                pModule.addModuleBody(pModBody);
                return pModule;
            }

        }
    }
}