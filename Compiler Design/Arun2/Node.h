#ifndef NODE_H
#define	NODE_H

#include <list>
#include <iostream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include "ST.hh"

using namespace std;


class Node {
public:
	int id;
	string type, value;
	list<Node*> children;

	Node(string t, string v) : type(t), value(v) {}
	Node()
	{
		type = "uninitialised";
		value = "uninitialised"; }   // Bison needs this.
  
  void printSyntaxTree(int depth=0) {
    for(int i=0; i<depth; i++)
      cout << "  ";
    cout << type << value << endl;
    for(auto i=children.begin(); i!=children.end(); i++)
      (*i)->printSyntaxTree(depth+1);
  }

  void generateSyntaxTree(int &count, ofstream *outStream) {
	  id = count++;
	  *outStream << "n" << id << " [label=\"" << type << value << "\"];" << endl;
auto i = children.begin();
	  while( i != children.end())
	  {
		  (*i)->generateSyntaxTree(count, outStream);
		  *outStream << "n" << id << " -> n" << (*i)->id << endl;
		  i++;
	  }
  }

//______________________________________________________________________________________________________________
// Symbol table traversing

	void traverseParameter(ST &st, Method* currentMethod){
		auto it = children.begin();
	  	std::string type = (*it)->value;
		if(type.compare("")==0 && ((*it)->type).compare("TypeVector")==0) 
			type="int[]";
		else if(type.compare("")==0)
			type="void";
		std::advance(it, 1);
		std::string name = (*it)->value;
		Variable *currentVar = new Variable(name, type);
		st.put(name, currentVar);
		currentMethod->addParameter(name, currentVar);
		std::advance(it, 1);
		if(it!=children.end()){ 
			std::advance(it, 1);
			(*it)->traverseParameter(st, currentMethod);
		}
		
  	}


	void traverseVariableMethod(ST &st, Method* currentMethod){
		auto it = children.begin();
	  	std::string type = (*it)->value;
		if(type.compare("")==0 && ((*it)->type).compare("TypeVector")==0) 
			type="int[]";
		else if(type.compare("")==0)
			type="void";
		std::advance(it, 1);
		std::string name = (*it)->value;
		Variable *currentVar = new Variable(name, type);
		st.put(name, currentVar);
		currentMethod->insertVariable(name, currentVar);
		
  }

	void traverseVariableDeclarationMethod(ST &st, Method* currentMethod){
		for(auto j=children.begin(); j!=children.end(); j++){
			if(((*j)->type).compare("VarDeclaration")==0){
					(*j)->traverseVariableMethod(st, currentMethod);
				}

				if(((*j)->type).compare("VarDeclarationList")==0){
					(*j)->traverseVariableDeclarationMethod(st, currentMethod);
				}
		}
	}

	void traverseVariableClass(ST &st, Class* currentClass){
		auto it = children.begin();
	  	std::string type = (*it)->value;
		if(type.compare("")==0 && ((*it)->type).compare("TypeVector")==0) 
			type="int[]";
		else if(type.compare("")==0)
			type="void";
		std::advance(it, 1);
		std::string name = (*it)->value;
		Variable *currentVar = new Variable(name, type);
		st.put(name, currentVar);
		currentClass->insertVariable(name, currentVar);
		
  }

	void traverseVariableDeclarationClass(ST &st, Class* currentClass){
		for(auto j=children.begin(); j!=children.end(); j++){
			if(((*j)->type).compare("VarDeclaration")==0){
					(*j)->traverseVariableClass(st, currentClass);
				}

				if(((*j)->type).compare("VarDeclarationList")==0){
					(*j)->traverseVariableDeclarationClass(st, currentClass);
				}
		}
	}

	void traverseMethod(ST &st, Class* currentClass){
		auto it = children.begin();
		std::advance(it, 1);
	  	std::string type = (*it)->value;
		if(type.compare("")==0 && ((*it)->type).compare("TypeVector")==0) 
			type="int[]";
		else if(type.compare("")==0)
			type="void";
		std::advance(it, 1);
		std::string name = (*it)->value;
		Method *currentMethod = new Method(name, type);
		st.put(name, currentMethod);
		currentClass->addMethod(name, currentMethod);
		st.enterScope();
		
		for(auto i=children.begin(); i!=children.end(); i++){
			if(((*i)->type).compare("VarDeclaration")==0){
				(*i)->traverseVariableMethod(st, currentMethod);
			}

			if(((*i)->type).compare("VarDeclarationList")==0){
				(*i)->traverseVariableDeclarationMethod(st, currentMethod);
			}
			
			if(((*i)->type).compare("ParameterList")==0){
				(*i)->traverseParameter(st, currentMethod);
			}
			
		}
		
		st.exitScope();
  }

 void traverseMethodDeclaration(ST &st, Class* currentClass){
	  for(auto j=children.begin(); j!=children.end(); j++){
		  if(((*j)->type).compare("MethodDeclaration")==0){
				(*j)->traverseMethod(st, currentClass);
			}

			if(((*j)->type).compare("MethodDeclarationList")==0){
				(*j)->traverseMethodDeclaration(st, currentClass);
			}
	  }
  }

  void traverseClass(ST &st){
		auto it = children.begin();
		std::advance(it, 1);
	  	std::string name = (*it)->value;
		Class *currentClass = new Class(name, name);
		st.put(name, currentClass);
		Variable *currentVariable = new Variable("this",name);
		
		currentClass->insertVariable("this",currentVariable);

		st.enterScope();
		st.put("this", currentVariable);
		for(auto i=children.begin(); i!=children.end(); i++){
			if(((*i)->type).compare("MethodDeclaration")==0){
				(*i)->traverseMethod(st, currentClass);
			}

			if(((*i)->type).compare("MethodDeclarationList")==0){
				(*i)->traverseMethodDeclaration(st, currentClass);
			}

			if(((*i)->type).compare("VarDeclaration")==0){
				(*i)->traverseVariableClass(st, currentClass);
			}

			if(((*i)->type).compare("VarDeclarationList")==0){
				(*i)->traverseVariableDeclarationClass(st, currentClass);
			}
		}
		st.exitScope();
		
  }

  void traverseMainClass(ST &st){
		auto it = children.begin();
		std::advance(it, 1);
	  	std::string name = (*it)->value;
		Class *currentClass = new Class(name, "int");
		st.put(name, currentClass);
		Variable *currentVariable = new Variable("this",name);
		
		currentClass->insertVariable("this",currentVariable);
		Method *currentMethod = new Method("main","void");
		
		currentClass->addMethod("main",currentMethod);
		std::string type = "String[]";
		std::advance(it, 10);
		std::string nameVar = (*it)->value;
		Variable *currentVariableMethod = new Variable(nameVar, type);
		currentMethod->insertVariable(name, currentVariableMethod);
		st.enterScope();
		st.put("this", currentVariable);
		st.put("main", currentMethod);
		st.enterScope();
		st.put(nameVar, currentVariableMethod);
		st.exitScope();
		st.exitScope();
  }

  void traverse(ST &st) {
	for(auto i=children.begin(); i!=children.end(); i++){
	  
	  if(((*i)->type).compare("MainClass")==0){
	  	  (*i)->traverseMainClass(st);
	  }

      if(((*i)->type).compare("ClassDeclarationList")==0){
	  	  (*i)->traverse(st);
	  }

	  if(((*i)->type).compare("ClassDeclaration")==0){
	  	  (*i)->traverseClass(st);
	  }

	  
  	}
  }

  void buildST(ST &st) {
	  std::cout << "-*-" << "\n";
	  std::cout << "Constructing the symbol table for the given testcase" << "\n\n";
	  st.SymbolTable();
	  traverse(st);
	  std::cout << "\n" << "-*-" << "\n\n";
  }

  void printST(ST &st){
	  std::cout << "-*-" << "\n";
	  std::cout << "The constructed symbol table is being printed" << "\n\n";
	  st.resetTable();
	  st.printTable();
	  std::cout << "\n" << "-*-" << "\n\n";
  }

	void traverseGetParameters(ST st, std::list<std::string> &l){
		string typeP;
		if(type.compare("ExpressionList")==0){	
			auto it=children.begin();
			
			if(((*it)->type).compare("Identifier")==0){
				Rec* rParameter = st.lookup((*it)->value);
				if(rParameter!=NULL)
				typeP = rParameter->getType();
			}else if(((*it)->type).compare("INTEGER")==0){
				typeP = "int";
			}else{
				(*it)->traverseGetParameters(st, l);
			}
			l.push_back(typeP);
			it++; it++;
			(*it)->traverseGetParameters(st,l);
		}else{
			if((type).compare("Identifier")==0){
				Rec* rParameter = st.lookup(value);
				if(rParameter!=NULL)
				typeP = rParameter->getType();
			}else if((type).compare("INTEGER")==0){
				typeP = "int";
			}else{
				typeP = traverseExpressionCheckType(st);
			}
			l.push_back(typeP);
		}
	}

	string traverseExpressionCheckType(ST &st) {		
		auto it=children.begin();
		string typeLHS;
		string typeRHS;
		string rType;

		if((type.compare("PlusExpression")==0) ||		
			(type.compare("MinusExpression")==0) ||
			(type.compare("lssExpression")==0) ||
			(type.compare("AndExpression")==0) ||
			(type.compare("MultExpression")==0)){
			if(((*it)->type).compare("Identifier")==0){
				Rec* rLHS = st.lookup((*it)->value);
				typeLHS = rLHS->getType();
			}else if(((*it)->type).compare("INTEGER")==0){
				typeLHS = "int";
			}else{
				typeLHS = (*it)->traverseExpressionCheckType(st);
			}
			it++;
			it++; 
			if(((*it)->type).compare("Identifier")==0){
				Rec* rRHS = st.lookup((*it)->value);
				typeRHS = rRHS->getType();
			}else if(((*it)->type).compare("INTEGER")==0){
				typeRHS = "int";
			}else{
				typeRHS = (*it)->traverseExpressionCheckType(st);
				
			}

			if(typeLHS != typeRHS){
				std::cout << type << " type on the left side (" << typeLHS << ") does not correspond to the type on the right side ("<< typeRHS << ")" << "\n";
				rType = "";
			}else{
				if((type.compare("lssExpression")==0) ||(type.compare("AndExpression")==0))
					rType="boolean";
				else
					rType=typeLHS;
			}

		}else if((type.compare("MethodCallExpression")==0) || 				
				(type.compare("MethodCallExpressionWithoutArgs")==0)){
					Rec* classRec;
					if(((*it)->type).compare("Identifier") == 0 ||
						((*it)->type).compare("KEYWORD") == 0){
						classRec = st.lookup((*it)->value);
						if(classRec!=NULL)
						if((classRec->getType()).compare(classRec->getId())){
							classRec = st.lookup(classRec->getType());
						}
					}else{
						string typeClass=(*it)->traverseExpressionCheckType(st);
						classRec = st.lookup(typeClass);
						
					}
					it++; it++;
					Rec* methodRec;
					if(classRec!=NULL){
						
						if((methodRec = classRec->lookupMethod((*it)->value)) != NULL){
							rType = methodRec->getType();
						}else if((classRec->getId()).compare("this") == 0){
							classRec = st.lookup(classRec->getType());
							if((methodRec = classRec->lookupMethod((*it)->value)) != NULL){
								rType = methodRec->getType();
							}
						}
					}
					
					if(methodRec!=NULL && classRec!= NULL){
						std::list<std::string> parametersMethod;
						methodRec->getParameters(parametersMethod);
						if(type.compare("MethodCallExpression")==0){
							std::list<std::string> parametersCall;
							it++; it++;
							(*it)->traverseGetParameters(st, parametersCall);
							if(parametersCall.size()!=parametersMethod.size()){
								std::cout << " error:"<<parametersCall.size()<<"in the method call"<<parametersMethod.size()<<") of the method "<< methodRec->getId() << "\n";
							}else{
								std::list<std::string>::iterator i = parametersCall.begin();
								std::list<std::string>::iterator j = parametersMethod.begin();
								
								for (int c = 1; i != parametersCall.end();c++){
									if((*i).compare((*j))!=0){
										std::cout << " error: "<<c<<"in the method call: (" << (*i) << "); Method "<<methodRec->getId()<<" parameter: ("<<(*j)<< ")\n";
									}
									i++; j++;
								}
							}
						}else{
							if(parametersMethod.size()>0){
								std::cout << "Method call error: the number of parameters of the call (0) does not match the number of parameters ("<<parametersMethod.size()<<") of the method "<< methodRec->getId() << "\n";
							}
						}
					}
		}else if((type.compare("NewVectorExpression")==0)){
			it++; it++; it++; 
			string typeLHS=(*it)->traverseExpressionCheckType(st);
			if(typeLHS.compare("int")==0){
				rType = "int[]";
			}else{
				std::cout << "New vector expression error: the type of the [expression] must be int not " << typeLHS << "\n";
			}
		}else if((type.compare("VectorAccessExpression")==0)){
			string typeLHS=(*it)->traverseExpressionCheckType(st);
			if(typeLHS.compare("int[]")==0){
				it++; it++;
				string typeRHS=(*it)->traverseExpressionCheckType(st);
				if(typeRHS.compare("int")==0){
					rType = "int";
				}else{
					std::cout << "Vector access error: the type of the int[expression] must be int not " << typeRHS << "\n";
				}
			}else{
				std::cout << "Vector access error: the type of the expression[] must be int[] not " << typeLHS << "\n";
			}
		}else if((type.compare("LITERAL")==0)){
			rType = "boolean";
		}else if((type.compare("NewClassExpression")==0)){
			it++; 
			Rec* r = st.lookup((*it)->value);
			if(r != NULL)
				rType = r->getType();
		}else if((type.compare("Identifier")==0)){
			
			Rec* r = st.lookup(value);
			if(r != NULL)
				rType = r->getType();
		}else if((type.compare("KEYWORD")==0)){
			Rec* r = st.lookup(value);
			if(r != NULL)
				rType = r->getType();

		}else if((type.compare("INTEGER")==0)){
			rType = "int";

		}else if((type.compare("LengthExpression")==0)){
			string typeLHS=(*it)->traverseExpressionCheckType(st);
			if(typeLHS.compare("int[]")==0){
				rType = "int";
			}else{
				std::cout << "Length attribute error: the type of the expression must be int[] not " << typeLHS << "\n";
			}

		}else if((type.compare("ParenExpression")==0) ||
				(type.compare("ExclamationExpression")==0)){
			
			it++;
			rType=(*it)->traverseExpressionCheckType(st);
		}
		
		return rType;
	}

	void findIdentifier(ST &st) {
		
		for(auto i=children.begin(); i!=children.end(); i++){
			bool exist = false;
			if(((*i)->type).compare("Identifier")==0){
				string v = ((*i)->value);
				Rec* r = st.lookup(v);
				if(r == NULL){
					if(type.compare("MethodCallExpression")==0 ||
						type.compare("MethodCallExpressionWithoutArgs")==0){
							
							auto it=children.begin();
							Rec* classRec;
							if(((*it)->type).compare("Identifier") == 0 ||
								((*it)->type).compare("KEYWORD") == 0){
								classRec = st.lookup((*it)->value);
								if(classRec!=NULL)
								if((classRec->getType()).compare(classRec->getId())){
									classRec = st.lookup(classRec->getType());
								}
							}else{
								string typeClass=(*it)->traverseExpressionCheckType(st);
								classRec = st.lookup(typeClass);
							}
							if(classRec!=NULL){
								
								if(classRec->lookupMethod(v) != NULL){
									exist = true;
								}
							}
						}
				}else{
					exist = true;
				}
				if(!exist){
					std::cout << "Error: identifier " << v << " has not been declared " <<"\n";
				}
			}
			(*i)->findIdentifier(st);
		}
		
	}

	void traverseMethodUndeclare(ST &st){

		st.enterScope();
			for(auto j=children.begin(); j!=children.end(); j++){
				(*j)->findIdentifier(st);
			}
		st.exitScope();
	}

	void traverseMethodDeclarationUndeclare(ST &st){
		for(auto j=children.begin(); j!=children.end(); j++){
			if(((*j)->type).compare("MethodDeclaration")==0){
					(*j)->traverseMethodUndeclare(st);
				}

				if(((*j)->type).compare("MethodDeclarationList")==0){
					(*j)->traverseMethodDeclarationUndeclare(st);
				}
		}
	}

	void traverseClassUndeclare(ST &st){
		
		st.enterScope();
		for(auto i=children.begin(); i!=children.end(); i++){
			
			if(((*i)->type).compare("MethodDeclaration")==0){
				(*i)->traverseMethodUndeclare(st);
			}

			if(((*i)->type).compare("MethodDeclarationList")==0){
				(*i)->traverseMethodDeclarationUndeclare(st);
			}
			
		}
		st.exitScope();
		
  }

  void traverseUndeclare(ST &st) {
	for(auto i=children.begin(); i!=children.end(); i++){

		
      if(((*i)->type).compare("ClassDeclarationList")==0){
	  	  (*i)->traverseUndeclare(st);
	  }

	  if(((*i)->type).compare("ClassDeclaration")==0){
		  
	  	  (*i)->traverseClassUndeclare(st);
	  }
	
	  if(((*i)->type).compare("MainClass")==0){
		  st.enterScope();
	  	  (*i)->traverseMethodUndeclare(st);
		  st.exitScope();
	  }
	  
  	}
  }

	void traverseAssignmentStatementCheckType(ST &st){
		auto it =children.begin();
		Rec* rLHS = st.lookup((*it)->value);
		
		if(rLHS != NULL){
			string typeLHS;
			typeLHS = rLHS->getType();
			it++; it++;
			string typeRHS;
			if(((*it)->type).compare("Identifier")==0){
				Rec* rRHS = st.lookup((*it)->value);
				typeRHS = rRHS->getType();
			}else if(((*it)->type).compare("INTEGER")==0){
				typeRHS = "int";
			}else if((((*it)->type).compare("KEYWORD")==0)){
				Rec* r = st.lookup((*it)->value);
					
				typeRHS = r->getType();
			}else{
				typeRHS = (*it)->traverseExpressionCheckType(st);
				
			}
			if(typeLHS != typeRHS){
				std::cout << "Assignment error: variable "<< rLHS->getId() << " with type on the left side(" << typeLHS << ") does not correspond to the type on the right side" << "\n";
			}
		}
	}

	void traverseConditionStatementCheckType(ST &st){
		auto it =children.begin();
		string name = type;
		it++; it++;
		string typeCondition = (*it)->traverseExpressionCheckType(st);
		
		if(typeCondition.compare("boolean")!=0){
			std::cout << "Condition error: the condition of the "<< name << " is not boolean" << "\n";
		}
		
	}

	void traversePrintStatementCheckType(ST &st){
		auto it =children.begin();
		it++; it++;
		string typePrint = (*it)->traverseExpressionCheckType(st);
		
		if(typePrint.compare("int")!=0){
			std::cout << "Print error: the type inside the System.out.println() is '" << typePrint << "' instead of 'int'" << "\n";
		}
		
	}

	void traverseVectorAssignmentStatementCheckType(ST &st){
		auto it =children.begin();
		string name = (*it)->value;
		string typeId = (*it)->traverseExpressionCheckType(st);
		it++; it++;
		string typeExpLHS = (*it)->traverseExpressionCheckType(st);
		it++; it++; it++;
		string typeExpRHS = (*it)->traverseExpressionCheckType(st);
		if(!((typeId.compare("int[]")==0) && (typeExpLHS.compare("int")==0) && (typeExpRHS.compare("int")==0))){
			std::cout << "Vector assignment error: type of identifier " << name << " (" << typeId << "); type expression access (" << typeExpLHS <<")" << "; type of right hand side (" << typeExpRHS << ")\n";
		}
		
	}

	void traverseStatementDeclarationCheckType(ST &st){
			
			for(auto j=children.begin(); j!=children.end(); j++){
				if(((*j)->type).compare("StatementList")==0){
						(*j)->traverseStatementDeclarationCheckType(st);
					}

					if(((*j)->type).compare("AssignmentStatement")==0){
						(*j)->traverseAssignmentStatementCheckType(st);
					}

					if(((*j)->type).compare("IFStatement")==0 ||
						((*j)->type).compare("WHILEStatement")==0){
						(*j)->traverseConditionStatementCheckType(st);
					}

					if(((*j)->type).compare("PrintStatement")==0){
						(*j)->traversePrintStatementCheckType(st);
					}

					if(((*j)->type).compare("VectorAssignmentStatement")==0){
						(*j)->traverseVectorAssignmentStatementCheckType(st);
					}
			}
	}

	void traverseMethodCheckType(ST &st){

		st.enterScope();
		
			for(auto j=children.begin(); j!=children.end(); j++){
				if(((*j)->type).compare("StatementList")==0){
						(*j)->traverseStatementDeclarationCheckType(st);
					}

					if(((*j)->type).compare("AssignmentStatement")==0){
						(*j)->traverseAssignmentStatementCheckType(st);
					}

					if(((*j)->type).compare("IFStatement")==0 ||
						((*j)->type).compare("WHILEStatement")==0){
						(*j)->traverseConditionStatementCheckType(st);
					}

					if(((*j)->type).compare("PrintStatement")==0){
						(*j)->traversePrintStatementCheckType(st);
					}

					if(((*j)->type).compare("VectorAssignmentStatement")==0){
						(*j)->traverseVectorAssignmentStatementCheckType(st);
					}
			}
			
			if(type.compare("MethodDeclaration")==0){
				auto j=children.begin();
				j++;
				string typeClass =  (*j)->value;
				if(typeClass.compare("")==0 && ((*j)->type).compare("TypeVector")==0) 
					typeClass="int[]";
				else if(typeClass.compare("")==0)
					typeClass="void";
				j++;
				string className = (*j)->value;
				j=children.end();
				j--; j--; j--;
				string typeReturn = (*j)->traverseExpressionCheckType(st);
				if(typeClass != typeReturn){
					std::cout << "Return error: the type of the method " <<  className << " (" << typeClass << ") is not the same of the return statement (" << typeReturn << ")\n";
				}
			}
			
		st.exitScope();
	}

	void traverseMethodDeclarationCheckType(ST &st){
		for(auto j=children.begin(); j!=children.end(); j++){
			if(((*j)->type).compare("MethodDeclaration")==0){
					(*j)->traverseMethodCheckType(st);
				}

				if(((*j)->type).compare("MethodDeclarationList")==0){
					(*j)->traverseMethodDeclarationCheckType(st);
				}
		}
	}

	void traverseClassCheckType(ST &st){
		
		st.enterScope();
		for(auto i=children.begin(); i!=children.end(); i++){
			
			if(((*i)->type).compare("MethodDeclaration")==0){
				(*i)->traverseMethodCheckType(st);
			}

			if(((*i)->type).compare("MethodDeclarationList")==0){
				(*i)->traverseMethodDeclarationCheckType(st);
			}
			
		}
		st.exitScope();
		
  }

  void traverseCheckType(ST &st) {
	for(auto i=children.begin(); i!=children.end(); i++){

		
      if(((*i)->type).compare("ClassDeclarationList")==0){
	  	  (*i)->traverseCheckType(st);
	  }

	  if(((*i)->type).compare("ClassDeclaration")==0){
	  	  (*i)->traverseClassCheckType(st);
	  }
	
	  if(((*i)->type).compare("MainClass")==0){
		  st.enterScope();
	  	  (*i)->traverseMethodCheckType(st);
		  st.exitScope();
	  }
	  
  	}
  }

   void checkSemantics(ST &st) {
	  std::cout << "-*-*-" << "\n";
	  std::cout << "checking of any undeclare variables is done here" << "\n\n";
	  st.resetTable();
	  traverseUndeclare(st);
	  std::cout << "\n" << "-*-*-" << "\n\n";

	  std::cout << "-*-*-" << "\n";
	  std::cout << "check for the identifier types" << "\n\n";
	  st.resetTable();
	  traverseCheckType(st);
	  std::cout << "\n" << "-*-*-" << "\n\n";
  }

};

#endif