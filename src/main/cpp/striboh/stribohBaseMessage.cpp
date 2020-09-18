//
// Created by grobap on 09.09.20.
//

#include "stribohBaseMessage.hpp"
#include "stribohBaseHoldInterface.hpp"
#include "stribohBaseMethodName.hpp"
#include "stribohBaseParameters.hpp"

namespace striboh {
    namespace base {
        Message::Message( const Signature&, const ParameterValues& ){

        }

        Message::Message() {

        }

        Message &Message::add(const ParameterValues& pValues) {
            mValues.add(pValues);
            return *this;
        }

    }
}