#include <iostream>
#include <queue>
#include <string>
#include <iomanip> 
#include <vector> 

using namespace std;

struct Customer
{
    int id;
    string name;
    int serviceTime; 

    Customer(int id, string name, int serviceTime)
        : id(id), name(name), serviceTime(serviceTime) {}
};

void displayQueue(queue<Customer> q)
{
    if (q.empty())
    {
        cout << "No customers in the queue." << endl;
        return;
    }

    cout << "Current Queue Status:" << endl;
    cout << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Service Time" << endl;
    cout << string(50, '-') << endl;

    while (!q.empty())
    {
        Customer c = q.front();
        cout << setw(10) << c.id << setw(20) << c.name << setw(15) << c.serviceTime << endl;
        q.pop();
    }
    cout << string(50, '-') << endl;
}

bool deleteCustomer(queue<Customer> &q, int customerId)
{
    vector<Customer> temp; 

    bool found = false;

    while (!q.empty())
    {
        Customer c = q.front();
        q.pop();

        if (c.id == customerId)
        {
            found = true; 
            cout << "Customer " << c.name << " (ID: " << c.id << ") has been removed from the queue." << endl;
        }
        else
        {
            temp.push_back(c); 
        }
    }

    for (const auto &c : temp)
    {
        q.push(c);
    }

    return found;
}

int main()
{
    queue<Customer> customerQueue;
    int customerId = 1; // add new customers 
    int choice;

    do
    {
        cout << "\nBank Queue Management System" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Serve Customer" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Delete Customer" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            int serviceTime;

            cout << "Enter customer name: ";
            cin >> name;
            cout << "Enter service time (in minutes): ";
            cin >> serviceTime;

            Customer newCustomer(customerId++, name, serviceTime);
            customerQueue.push(newCustomer);
            cout << "-----Customer added to the queue-----" << endl;
            break;
        }
        case 2:
        {
            if (customerQueue.empty())
            {
                cout << "-----No customers to serve!!!-----" << endl;
            }
            else
            {
                Customer servedCustomer = customerQueue.front();
                customerQueue.pop();
                cout << "Serving customer: " << servedCustomer.name
                     << " (ID: " << servedCustomer.id
                     << ") with service time: " << servedCustomer.serviceTime << " minutes." << endl;
            }
            break;
        }
        case 3:
        {
            displayQueue(customerQueue);
            break;
        }
        case 4:
        {
            int customerIdToDelete;
            cout << "Enter the customer ID to delete: ";
            cin >> customerIdToDelete;

            if (!deleteCustomer(customerQueue, customerIdToDelete))
            {
                cout << "Customer with ID " << customerIdToDelete << " not found." << endl;
            }
            break;
        }
        case 5:
        {
            cout << "Exiting the program." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 5);

    return 0;
}
