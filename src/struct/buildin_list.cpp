#include <vector>
#include <iostream>
#include "struct.h"

namespace ipyhon {

typedef std::vector<any> List;
typedef GeneralObject<List> ListObject;
typedef std::shared_ptr<ListObject> ListPtr;

struct ListAdd {
    any operator()(const any& l, const any& r) {
        if (l.type() != r.type() || l.type() != typeid(List)) {
            return any();
        }
        any res = l;
        ListPtr rp = std::dynamic_pointer_cast<ListObject>(r.get_content());
        ListPtr p = std::dynamic_pointer_cast<ListObject>(res.get_content());
        p->_core.insert(p->_core.end(), rp->_core.begin(), rp->_core.end());
        return res;
    }
};

struct ListPrint {
	void operator()(const any& l) {
		assert(l.type() == typeid(List));
		List& self = l.get_refer<List>();
		for (auto& element: self) {
			;
		}
		return;
	}
};

ListType::ListType() {
    tp_print = ListPrint();
    tp_as_number.nb_add = ListAdd();
}

}
