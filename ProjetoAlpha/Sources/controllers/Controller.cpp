/*
 * Controller.cpp
 *
 *  Created on: 21/04/2021
 *      Author: pbs
 */
#include <iostream>
#include <string>
#include <tuple>
#include "Controller.h"
#include "Utils.h"
#include "DataConsistencyException.h"


using namespace std;



Controller::Controller(School& school){
	this->model = school;
}

void Controller::run(){
	int op = -1;
	do{
		op=this->view.menuSchool();
		switch(op){
		case 1:runStudents();
		break;
		case 2:runInstructors();
		break;
		case 3:runSubjects();
		break;
		case 4:runEnrolls();
		break;
		default:
			break;
		}
	}while(op!=0);

}

void Controller::runStudents(){


	int op = -1;
	do{
		op = this->view.menuStudents();

		switch(op){
		case 1:	{
			Student student = this->studentView.getStudent();
			StudentContainer& container = this->model.getStudentContainer();
			container.add(student);
		}
		break;
		case 2:{
			int number = Utils::getNumber("Enter the Student Number");
			StudentContainer& container = this->model.getStudentContainer();
			Student * ptr = container.get(number);
			if(ptr != NULL){
				this->studentView.printStudent(ptr);
			}else{
				cout<<"Student ["<<to_string(number) <<"] does not exist."<<endl;
			}
		}
		break;
		case 3:{
			try{
				int number = Utils::getNumber("Enter the Student Number");
				StudentContainer& container = this->model.getStudentContainer();
				container.remove(number);
			}catch(DataConsistencyException& e){
				string str(e.what());
				cout<<str<<endl;
			}
		}
		break;
		case 4:{
			int number = Utils::getNumber("Enter the Student Number");
			string name =  Utils::getString("Enter the Student Name");
			Date date = this->studentView.getDate();
			StudentContainer& container = this->model.getStudentContainer();
			container.update(number,name, date);
		}
		break;
		case 5:
		{
			cout<<this->model.getName()<<endl;
			StudentContainer container = this->model.getStudentContainer();
			list<Student> students = container.getAll();
			this->studentView.printStudents(students);

		}
		break;
		default:
			break;
		}
	}while(op!=0);
}

void Controller::runInstructors(){

	int op = -1;
	do{
		op = this->view.menuInstructors();

		switch(op){
		case 1:	{
			Instructor instructor = this->instructorView.getInstructor();
			InstructorContainer& container = this->model.getInstructorContainer();
			container.add(instructor);
		}
		break;
		case 2:{
			string initials = Utils::getString("Enter the Instructor Initials");
			InstructorContainer& container = this->model.getInstructorContainer();
			Instructor * ptr = container.get(initials);
			if(ptr != NULL){
				this->instructorView.printInstructor(ptr);
			}else{
				cout<<"Instructor ["<< initials <<"] does not exist."<<endl;
			}
		}
		break;
		case 3:{
			try{
				string initials = Utils::getString("Enter the Instructor Initials");
				InstructorContainer& container = this->model.getInstructorContainer();
				container.remove(initials);
			}catch(DataConsistencyException& e){
				string str(e.what());
				cout<<str<<endl;
			}
		}
		break;
		case 4:{
			string initials = Utils::getString("Enter the Instructor Initials");
			string name =  Utils::getString("Enter the Instructor Name");
			InstructorContainer& container = this->model.getInstructorContainer();
			container.update(initials,name);
		}
		break;
		case 5:
		{
			cout<<this->model.getName()<<endl;
			InstructorContainer container = this->model.getInstructorContainer();
			list<Instructor> instructors = container.getAll();
			this->instructorView.printInstructors(instructors);

		}
		break;

		case 6:runLectures();
		break;
		default:
			break;
		}
	}while(op!=0);
}
void Controller::runSubjects(){


	int op = -1;
	do{
		op = this->view.menuSubjects();

		switch(op){
		case 1:	{
			Subject subject = this->subjectView.getSubject();
			SubjectContainer& container = this->model.getSubjectContainer();
			container.add(subject);
		}
		break;
		case 2:{
			string initials = Utils::getString("Enter the Subject Initials");
			SubjectContainer& container = this->model.getSubjectContainer();
			Subject * ptr = container.get(initials);
			if(ptr != NULL){
				this->subjectView.printSubject(ptr);
			}else{
				cout<<"Subject ["<< initials <<"] does not exist."<<endl;
			}
		}
		break;
		case 3:{
			try{
				string initials = Utils::getString("Enter the Subject Initials");
				SubjectContainer& container = this->model.getSubjectContainer();
				container.remove(initials);
			}catch(DataConsistencyException& e){
				string str(e.what());
				cout<<str<<endl;
			}
		}
		break;
		case 4:{
			string initials = Utils::getString("Enter the Subject Initials");
			string designation =  Utils::getString("Enter the Subject Designation");
			SubjectContainer& container = this->model.getSubjectContainer();
			container.update(initials,designation);
		}
		break;
		case 5:
		{
			cout<<this->model.getName()<<endl;
			SubjectContainer container = this->model.getSubjectContainer();
			list<Subject> subjects = container.getAll();
			this->subjectView.printSubjects(subjects);

		}
		break;

		default:
			break;
		}
	}while(op!=0);
}
void Controller::runEnrolls(){


	int op = -1;
	do{
		op = this->view.menuEnrolls();

		switch(op){
		case 1:	{
			Enroll enroll = this->enrollView.getEnroll(this->model.getStudentContainer(), this->model.getSubjectContainer());
			EnrollContainer& container = this->model.getEnrollContainer();
			container.add(enroll);
		}
		break;
		case 2:{
			int number = Utils::getNumber("Enter Student Number");
			string initials = Utils::getString("Enter Subject Initials");
			EnrollContainer& container = this->model.getEnrollContainer();
			Enroll * ptr = container.get(number, initials);
			if(ptr != NULL){
				this->enrollView.printEnroll(ptr);
			}else{
				cout<<"Enroll ["<< initials <<"] does not exist."<<endl;
			}
		}
		break;
		case 3:{
			try{
				int number = Utils::getNumber("Enter Student Number");
				string initials = Utils::getString("Enter Subject Initials");
				EnrollContainer& container = this->model.getEnrollContainer();
				container.remove(number, initials);
			}catch(DataConsistencyException& e){
				string str(e.what());
				cout<<str<<endl;
			}
		}
		break;
		case 4:
		{
			cout<<this->model.getName()<<endl;
			EnrollContainer container = this->model.getEnrollContainer();
			list<Enroll> enrolls = container.getAll();
			this->enrollView.printEnrolls(enrolls);

		}
		break;
		case 5:
		{
			int number = Utils::getNumber("Enter Student Number");
			StudentContainer& container = this->model.getStudentContainer();
			Student * student = container.get(number);
			if(student != NULL){
				EnrollContainer& container1 = this->model.getEnrollContainer();
				list<tuple<Subject *, int>> l = container1.getSubjects(number);
				this->enrollView.printStudentEnrolls(student, l);
			}


		}
		break;
		case 6:
		{
			string initials = Utils::getString("Enter Subject Initials");
			SubjectContainer& container = this->model.getSubjectContainer();
			Subject * subject = container.get(initials);
			if(subject != NULL){
				EnrollContainer& container1 = this->model.getEnrollContainer();
				list<Student *> l = container1.getStudents(initials);
				this->enrollView.printSubjectEnrolls(subject, l);
			}


		}
		break;


		default:
			break;
		}
	}while(op!=0);
}

void Controller::runLectures(){


	int op = -1;
	do{
		op = this->view.menuLectures();

		switch(op){
		case 1:	{
			string initials = Utils::getString("Enter the Instructor Initials");
			InstructorContainer& container = this->model.getInstructorContainer();
			Instructor * instructor = container.get(initials);
			if(instructor != NULL){
				Lecture lecture = this->lectureView.getLecture(this->model.getSubjectContainer());
				LectureContainer& container1 = instructor->getLectures();
				container1.add(lecture);
			}else{
				cout<<"Instructor ["<< initials <<"] does not exist."<<endl;
			}
		}
		break;
		case 2:{
			string initials = Utils::getString("Enter the Instructor Initials");
			InstructorContainer& container = this->model.getInstructorContainer();
			Instructor * instructor = container.get(initials);
			if(instructor != NULL){
				string initials1 = Utils::getString("Enter the Subject Initials");
				LectureContainer& container1 = instructor->getLectures();
				container1.remove(initials1);
			}else{
				cout<<"Instructor ["<< initials <<"] does not exist."<<endl;
			}
		}
		break;
		case 3:	{
			string initials = Utils::getString("Enter the Instructor Initials");
			InstructorContainer& container = this->model.getInstructorContainer();
			Instructor * instructor = container.get(initials);
			if(instructor != NULL){
				LectureContainer& container1 = instructor->getLectures();
				list<Lecture> listLecture = container1.getAll();
				this->lectureView.printLectures(instructor, listLecture);
			}else{
				cout<<"Instructor ["<< initials <<"] does not exist."<<endl;
			}
		}
		break;



		default:
			break;
		}
	}while(op!=0);
}
