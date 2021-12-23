#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct avl_node
{
	string FName, LName, CNIC, DOB, Address, Nationality, City, Phone_Number, status;
	int Date_of_Submission[3];
	char Gender;
	int type;
	long int Password;
	struct avl_node *left;
	struct avl_node *right;
};
class avlTree
{
public:
	void Refile(avl_node *tree);
	avl_node*findminmumnumber(avl_node*root);
	avl_node*Delete(avl_node *root, string data);
	int height(avl_node *);
	int diff(avl_node *);
	void Changestatus(avl_node*root, string cnic);
	avl_node *rr_rotation(avl_node *);
	avl_node *ll_rotation(avl_node *);
	avl_node *lr_rotation(avl_node *);
	avl_node *rl_rotation(avl_node *);
	avl_node* balance(avl_node *);
	avl_node* insert(avl_node*root, int Date_of_Submission[],string DATA[], char Gender, int type, int Password);
	void  Seeinformation(avl_node*root, string CNIC);
	void inorder(avl_node *tree);
	void  Userinformation(avl_node*root, string CNIC,int Date[]);

};
