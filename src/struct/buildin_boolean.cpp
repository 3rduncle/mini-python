#include "struct.h"

namespace ipyhon {

BooleanType::BooleanType() {
	tp_print = PrintHelper<bool>();
    tp_string = ToStringHelper<bool>();
	tp_hash = HashHelper<bool>();
}

}
