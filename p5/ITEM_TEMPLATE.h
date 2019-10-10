#ifndef ITEM_TEMPLATE_H_
#define ITEM_TEMPLATE_H_

using namespace std;

class ITEM {
public:
	string name;
	int quantity;
	ITEM() : name(""), quantity(0){}
	~ITEM() {}
	ITEM(string name) : name(name), quantity(0) {}
	bool Process_Purchase(istream &cin, ostream &cout) {
		return true;
	}
	int Get_Cost() const {
		cout<<"don't call this function"<<endl;
		return 0;
	}
	bool operator<(const ITEM& rhs) {
		return this->name < rhs.name;
	}
	void Print(ostream &out=cout) const {
		out<<"Print the derived class info instead of this"<<endl;
	}
};
ostream & operator<<(ostream &out, const ITEM &rhs) {
	rhs.Print(out);
	return out;
}
bool compare_pointers_to_items(ITEM *lhs, ITEM *rhs) {
	return *lhs < *rhs;
}


class BALLS : public ITEM {};
class RUM : public ITEM {};
class LIMES : public ITEM {};
class APPAREL : public ITEM {};
#endif
