#include <unordered_map>
#include "struct.h"

namespace ipython {

typedef std::unordered_map<any, any> Dict;
typedef GeneralObject<Dict> DictObject;
typedef std::shared_ptr<DictObject> DictPtr;

DictType::DictType() {
}

}
