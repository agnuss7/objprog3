## V0.2

Operatorių realizacija ir Doxygen dokumentacija. Taip pat patobulinau skirstimą į gerus/blogus studentus.

#Operatoriai

Vienintelis operatorius, kuris šiuo atveju buvo naudingas buvo "<<" spausdinant tam tikrą info apie studentą (print metodas vis dar liko ir spausdina kitokią info).

#Doxygen

Prirašinėjau komentarų, kurie bus matomi Doxygen dokumentacijoj.

#std::partition

whoa, kartais daugiau nei per pusę sumažina laiko sąnaudas.

#coolish things

Klasės patogios. Doxygen irgi.

class studentai

{

	private:
    std::string var;

    std::string pav;

    std::vector<std::size_t> paz;

    std::size_t egz;

    float vidnd;

    float mednd;

    float vidtotal;

    float medtotal;
public:
///cia default konstruktorius
studentai() :egz(0) {}
studentai(std::istream &in);
void add (std::string & name, std::string & sname, std::size_t & e, std::vector<std::size_t> & p); 
~studentai() {};
std::istream& read(std::istream& in);
void mediana();
void vidurkis();
float getVid() const;
float getMed() const;
inline std::string getPav() const;
void print(bool a);
friend std::ostream& operator<<(std::ostream& out, const studentai& f);
};
