#ifndef STUDENT_H
#define STUDENT_H

class Student {
	char nume[50];
	float nota_mate;
	float nota_engleza;
	float nota_istorie;

public:
	Student();

	void setNume(const char* numeStudent);
	const char* getNume() const;

	void setNotaMate(float nota);
	float getNotaMate() const;

	void setNotaEngleza(float nota);
	float getNotaEngleza()const;

	void setNotaIstorie(float nota);
	float getNotaIstorie() const;

	float getMedia() const;
};


#endif // !STUDENT_H
