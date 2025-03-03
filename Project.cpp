#include <iostream>
using namespace std;

string medicines[100][4];
int medicineCount = 0;

bool login()
{
    string admin, password;
    string admin_verified = "Ghazanfar", password_verified = "Ghazanfar123";
    int attempts = 0;

    while (attempts < 3)
    {
        cout << "Admin: ";
        cin >> admin;
        cout << "Password: ";
        cin >> password;

        if (admin == admin_verified && password == password_verified)
        {
            system("clear");
            cout << "Welcome to the administration portal.\n";
            return true;
        }
        else
        {
            cout << "Incorrect credentials. Try again.\n";
            attempts++;
        }
    }
    cout << "Too many failed attempts. Exiting...\n";
    return false;
}

void addMedicine()
{
    if (medicineCount >= 100)
    {
        cout << "Medicine storage full!\n";
        return;
    }

    cout << "Enter medicine name: ";
    cin >> medicines[medicineCount][0];
    cout << "Enter quantity: ";
    cin >> medicines[medicineCount][1];
    cout << "Enter price: ";
    cin >> medicines[medicineCount][2];
    cout << "Enter expiry date: ";
    cin >> medicines[medicineCount][3];
    
    medicineCount++;
    cout << "Medicine added successfully!\n";
}

void deleteMedicine()
{
    string name;
    cout << "Enter medicine name to delete: ";
    cin >> name;
    
    for (int i = 0; i < medicineCount; i++)
    {
        if (medicines[i][0] == name)
        {
            for (int j = i; j < medicineCount - 1; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    medicines[j][k] = medicines[j + 1][k];
                }
            }
            medicineCount--;
            cout << "Medicine deleted successfully!\n";
            return;
        }
    }
    cout << "Medicine not found!\n";
}

void listMedicines()
{
    if (medicineCount == 0)
    {
        cout << "No medicines available!\n";
        return;
    }
    
    cout << "\n--- Medicine List ---\n";
    for (int i = 0; i < medicineCount; i++)
    {
        cout << "Name: " << medicines[i][0] << ", Quantity: " << medicines[i][1] << ", Price: " << medicines[i][2] << ", Expiry: " << medicines[i][3] << "\n";
    }
}

int main()
{
    cout << "--Pharmacy Database System--" << endl;

    if (!login())
        return 0;

    int choice;
    do {
        cout << "\n1. Add Medicine\n2. Delete Medicine\n3. List Medicines\n4. Exit\nEnter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
        case 1:
            addMedicine();
            break;
        case 2:
            deleteMedicine();
            break;
        case 3:
            listMedicines();
            break;
        case 4:
            cout << "\nExiting the system. Goodbye!\n";
            break;
        default:
            cout << "\nInvalid choice! Please select a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}
