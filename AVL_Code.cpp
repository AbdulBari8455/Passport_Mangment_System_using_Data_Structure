#include"Avl.h"
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int avlTree::height(avl_node *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

/*
* Height Difference
*/
int avlTree::diff(avl_node *temp)
{
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	int b_factor = l_height - r_height;
	return b_factor;
}

/*
* Right- Right Rotation
*/
avl_node *avlTree::rr_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}
/*
* Left- Left Rotation
*/
avl_node *avlTree::ll_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

/*
* Left - Right Rotation
*/
avl_node *avlTree::lr_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->left;
	parent->left = rr_rotation(temp);
	return ll_rotation(parent);
}

/*
* Right- Left Rotation
*/
avl_node *avlTree::rl_rotation(avl_node *parent)
{
	avl_node *temp;
	temp = parent->right;
	parent->right = ll_rotation(temp);
	return rr_rotation(parent);
}

/*
* Balancing AVL Tree
*/
avl_node *avlTree::balance(avl_node *temp)
{
	int bal_factor = diff(temp);
	if (bal_factor > 1)
	{
		if (diff(temp->left) > 0)
			temp = ll_rotation(temp);
		else
			temp = lr_rotation(temp);
	}
	else if (bal_factor < -1)
	{
		if (diff(temp->right) > 0)
			temp = rl_rotation(temp);
		else
			temp = rr_rotation(temp);
	}
	return temp;
}

/*
* Insert Element into the tree
*/
avl_node *avlTree::insert(avl_node*root,  int Date_of_Submission[], string DATA[], char Gender, int type, int Password)
{
	if (root == NULL)
	{
		root = new avl_node;
		root->FName = DATA[0];
		root->LName = DATA[1];
		root->CNIC = DATA[2];
		root->DOB = DATA[3];
		root->Address = DATA[5];
		root->Nationality = DATA[7];
		root->City = DATA[6];
		root->Date_of_Submission[0] = Date_of_Submission[0];
		root->Date_of_Submission[1] = Date_of_Submission[1];
		root->Date_of_Submission[2] = Date_of_Submission[2];
		root->Phone_Number = DATA[4];
		root->type = type;
		root->Gender = Gender;
		root->Password = Password;
		root->status = DATA[8];
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (DATA[2] < root->CNIC)
	{
		root->left = insert(root->left,  Date_of_Submission, DATA, Gender, type, Password);
		root = balance(root);
	}
	else if (DATA[2] >= root->CNIC)
	{
		root->right = insert(root->right,  Date_of_Submission, DATA, Gender, type, Password);
		root = balance(root);
	}
	return root;
}

void avlTree::Seeinformation(avl_node*root, string idc)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		if (root->CNIC > idc)
		{
			Seeinformation(root->left, idc);
		}
		else if (root->CNIC < idc)
		{
			Seeinformation(root->right, idc);
		}
		if (root->CNIC == idc)
		{
			cout << "Name is               :> " << root->FName << " " << root->LName << endl;
			cout << "DOF is                :> " << root->DOB << endl;
			cout << "CNIC                  :> " << root->CNIC << endl;
			cout << "Gender                :> " << root->Gender << endl;
			cout << "Address               :> " << root->Address << endl;
			cout << "City                  :> " << root->City << endl;
			cout << "Nationality           :> " << root->Nationality << endl;
			cout << "Date of Submission    :> " << root->Date_of_Submission[0] << "-" << root->Date_of_Submission[1] << "-" << root->Date_of_Submission[2] << endl;
			cout << "Phone Number is       :> " << root->Phone_Number << endl;
			cout << "Status                :> " << root->status << endl;
			cout << endl<<endl<<endl;
			if (root->status == "P")
			{
				cout << "iF you Want to Change Any Data you have provided press 1" << endl;
				int i = 0;
				cin >> i;
				if (i != 1)
				{
					return;
				}
				else
				{
					while (1)
					{
						cout << "Which Information Do you Want to Change " << endl;
						cout << "Press 1 to Change Name " << endl;
						cout << "Press 2 to Change Date of Birth " << endl;
						cout << "Press 3 to Change Gender " << endl;
						cout << "Press 4 to Change Address " << endl;
						cout << "Press 5 to Change City " << endl;
						cout << "Press 6 to Change Nationality " << endl;
						cout << "Press 7 to Change Phone Number" << endl;
						cout << "Press 8 to Exite" << endl;
						int C = 0;
						cin >> C;
						switch (C)
						{
						case 1:
							cout << "Enter New Name " << endl;
							cin >> root->FName >> root->LName;
							break;
						case 2:
							cout << "Enter New Date Of Birth " << endl;
							cin >> root->DOB;
							break;
						case 3:
							cout << "Change Gender " << endl;
							cin >> root->Gender;
							break;
						case 4:
							cout << "Enter New Address " << endl;
							cin >> root->Address;
							break;
						case 5:
							cout << "Enter New City Name " << endl;
							cin >> root->City;
							break;
						case 6:
							cout << "Enter New NAtionality" << endl;
							cin >> root->Nationality;
							break;
						case 7:
							cout << "Enter New Phone Number " << endl;
							cin >> root->Phone_Number;
							break;
						case 8 :
							return;
						default:
							cout << "Enter Right Choice" << endl;
							break;
						}
					}
					
					

				}
			}
			
		}
	}
}
void avlTree::Userinformation(avl_node*root, string CNIC,int Date[])
{
	if (root == NULL)
	{
		cout << "BST is Empty " << endl;
		return;
	}
	else
	{
		if (root->CNIC > CNIC)
		{
			Userinformation(root->left, CNIC, Date);
		}
		else if (root->CNIC < CNIC)
		{
			Userinformation(root->right,CNIC, Date);
		}
		if (root->CNIC == CNIC)
		{
			if (Date[2] - root->Date_of_Submission[2] >= 0)
			{
				if (Date[1] - root->Date_of_Submission[1] >= 0)
				{
					if (Date[0] - root->Date_of_Submission[0] >= 0)
					{
						if (root->type == 4 && root->status == "P" && (Date[2] - root->Date_of_Submission[2] >= 0 || Date[1] - root->Date_of_Submission[1] >= 0) || Date[0] - root->Date_of_Submission[0] >=10)
						{
							cout << "Your Passport Is Ready  you can Take your Password " << endl;
							root->status = "Given";
						}
						else if (root->type == 5 && root->status == "P" && (Date[2] - root->Date_of_Submission[2] >= 0 || Date[1] - root->Date_of_Submission[1] >= 0) || Date[0] - root->Date_of_Submission[0] >=20)
						{
							cout << "Your Passport Is Ready  you can Take your Password " << endl;
							root->status = "Given";
						}
						else if (root->status != "P")
						{
							cout << "Passport Is Already Given to User " << endl;
						}
						else
						{
							cout << "Your Passport Is In process " << endl;
							cout << "You Have to Wait :>" << Date[0] - root->Date_of_Submission[0] << " Days" << endl;

						}
					}
				}
				else
				{
					cout << "You Enter Wrong Date " << endl;
					return;
				}
			}
			else
			{
				cout << "You Enter Wrong Date " << endl;
				return;
			}
		}
		
	}
}
avl_node* avlTree::Delete(avl_node *root, string data) 
{
	if (root == NULL) return root;
	else if (data < root->CNIC) root->left = Delete(root->left, data);
	else if (data > root->CNIC) root->right = Delete(root->right, data);

	else {

		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}

		else if (root->left == NULL) {
			avl_node *temp = root;
			root = root->right;
			root = balance(root);
			delete temp;
			temp = NULL;
		}
		else if (root->right == NULL) {
			avl_node*temp = root;
			root = root->left;
			root = balance(root);
			delete temp;
			temp = NULL;
		}

		else {
			avl_node *temp = findminmumnumber(root->right);
			swap(root->CNIC, temp->CNIC);
			root->right = Delete(root->right, temp->CNIC);
		}
	}
	return root;
}
avl_node*avlTree::findminmumnumber(avl_node*root)
{
	if (root == NULL)
	{
		cout << "BST is Empty " << endl;
		return NULL;
	}
	else
	{
		avl_node*curr = root;
		while (curr->left != NULL)
		{
			curr = curr->left;
		}
		return curr;
	}

}
void avlTree::inorder(avl_node *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	cout << "Name is               :> " << tree->FName << " " << tree->LName << endl;
	cout << "DOF is                :> " << tree->DOB << endl;
	cout << "CNIC                  :> " << tree->CNIC << endl;
	cout << "Gender                :> " << tree->Gender << endl;
	cout << "Address               :> " << tree->Address << endl;
	cout << "City                  :> " << tree->City << endl;
	cout << "Nationality           :> " << tree->Nationality << endl;
	cout << "Date of Submission    :> " << tree->Date_of_Submission[0] << "-" << tree->Date_of_Submission[1] << "-" << tree->Date_of_Submission[2] << endl;
	cout << "Phone Number is       :> " << tree->Phone_Number << endl;
	cout << "Status                :> " << tree->status << endl;
	inorder(tree->right);
}
void avlTree::Changestatus(avl_node*root,string Cnic)
{
	if (root == NULL)
	{
		cout << "BST is Empty " << endl;
	}
	else
	{
		if (root->CNIC > Cnic)
		{
			Changestatus(root->left, Cnic);
		}
		else if (root->CNIC <Cnic)
		{
			Changestatus(root->right, Cnic);
		}
		if (root->CNIC == Cnic)
		{
			root->status == "Given";
			cout << "Your Passport process is Complete Know you Can take your Passport" << endl;
			return;
		}

	}
}
void avlTree::Refile(avl_node *tree)
{
	if (tree == NULL)
		return;
	inorder(tree->left);
	ofstream file;
	file.open("Endingfile.txt", ios::app);
	file << tree->FName << " " << tree->LName << " " << tree->CNIC << " " << tree->DOB << " " << tree->Date_of_Submission[0] << " " << tree->Date_of_Submission[1];
	file << " " << tree->Date_of_Submission[2] << " " << tree->Phone_Number << " " << tree->Address << " " << tree->City << " " << tree->Nationality << " " << tree->Gender;
	file << " " << tree->type << " " << tree->Password << " " << tree->status << endl;
	file.close();
	inorder(tree->right);
}
