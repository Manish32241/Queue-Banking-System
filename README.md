# Queue-Banking-System
Bank Queue Management System
This C++ program simulates a queue management system for a bank, allowing efficient handling of customer arrivals, services, and departures. The program uses a queue data structure to maintain a sequence of customers and provides a simple menu-driven interface for user interaction.

Features
Customer Structure:

The Customer struct models each customer with:
id: A unique identifier for each customer.
name: Customer’s name.
serviceTime: Estimated time needed to complete the service (in minutes).
This struct enables easy handling and display of customer data.
Queue Management Functions:

displayQueue: Displays the current state of the queue with headers for ID, Name, and Service Time. It uses formatted output for clear, tabular presentation and shows a message if the queue is empty.
deleteCustomer: Allows deletion of a specific customer by ID. It temporarily removes all customers from the queue to check each ID, only pushing back customers that don't match the ID to be deleted. A message confirms successful deletion or informs if the customer was not found.
Main Program Workflow:

The program uses a loop to display a menu with options for managing the queue:
Add Customer:
Prompts the user for the customer's name and service time, then creates a Customer object with a unique ID, which increments with each new customer.
The customer is added to the end of the queue.
Serve Customer:
If the queue is not empty, this option serves the first customer (the one at the front), removes them from the queue, and displays their details.
If the queue is empty, it notifies that no customers are available to serve.
Display Queue:
Calls displayQueue to show the current state of the queue.
Delete Customer:
Prompts the user for the customer ID to delete, then calls deleteCustomer.
If the ID is found, the customer is removed from the queue; otherwise, an error message is shown.
Exit:
Terminates the program.

The interface is straightforward, presenting a text menu and responding to user input. Here’s a sample interaction:
Bank Queue Management System
  1. Add Customer
  2. Serve Customer
  3. Display Queue
  4. Delete Customer
  5. Exit
Enter your choice: 1
Enter customer name: John
Enter service time (in minutes): 15
-----Customer added to the queue-----

--Additional Notes--
  Efficiency: The program uses a queue structure to ensure first-in, first-out (FIFO) service.
  Edge Handling: Displays relevant messages for empty queue scenarios and invalid customer IDs to improve user experience.
This program can be expanded to support more complex customer management systems with additional features like priority handling or more robust data validation.
