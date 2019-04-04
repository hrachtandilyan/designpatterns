#include <string>
#include <vector>
class IPerson
{
public:
	virtual IPerson* Clone() = 0;
	IPerson(const std::string& p_name, int id) :p_name(p_name), p_ID(id) { }
	IPerson(const IPerson& person) {
		this->p_name = person.p_name;
		this->p_ID = person.p_ID;
	}
	void SetID(int ID) { p_ID = ID; }
private:
	std::string p_name;
	int p_ID;
};

class Pupil : public IPerson
{
public:
	Pupil(const std::string& p_name, int id) :IPerson(p_name, id)
	{

	}
	Pupil(const Pupil& pupil) :IPerson(pupil)
	{

	}

	IPerson* Clone()
	{
		return new Pupil(*this);
	}
};
class Teacher : public IPerson
{
public:
	Teacher(const std::string& t_name, int id) :IPerson(t_name, id)
	{

	}

	Teacher(const Teacher& teacher) :IPerson(teacher)
	{

	}

	IPerson* Clone()
	{
		return new Teacher(*this);
	}
};

class School
{
public:

	School(const std::string& sName) :school_name(sName)
	{

	}
	void AddMember(IPerson* ptr) { Members.push_back(ptr); }
private:
	std::vector<IPerson*> Members;
	std::string school_name;
};