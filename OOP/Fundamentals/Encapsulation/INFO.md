# **Encapsulation in C++**

![Lightbox](https://media.geeksforgeeks.org/wp-content/uploads/20221207132325/ecapsulation_in_cpp.png "Encapsulation")

**Encapsulation** in C++ is a fundamental concept in object-oriented programming (OOP). It combines data and the functions that operate on that data into a single unit, such as a class. The main goal of encapsulation is to hide sensitive data from users. This is achieved by defining a class’s variables (data members) as private. This ensures controlled access to the data and prevents unauthorized modification. In short, encapsulation enhances code security and maintainability.

## **Keywords Related to Encapsulation in C++ Core keywords**

* **encapsulation:** Hiding data and burying implementation inside a class.
* **`class`:** A template that defines data and the functions that operate on that data.
* **`private`:** Restricted access within the class only.
* **`public`:** Access from anywhere.
* **`protected`:** Access within the class and its derived classes.
* **data members:** Variables that store the state.
* **member functions / methods:** Functions that implement operations on the data.
* **access control:** Mechanisms to determine who can access the members.
* **abstraction:** Hiding complex details and presenting a simple interface.
* **interface:** The set of public functions that allow interaction with the object.

### **Related concepts**

* **`getter` / `setter`:** Accessor methods to read and write member values safely.
* **`constructor` / `destructor`:** Setup and cleanup of resources when objects are created/destroyed.
* **`nullability` / `invariants`:** Maintaining object validity through internal rules.
* **`friend`:** Allowing a class or function to access private members (in special cases).

## **Benefits of Encapsulation**

* **Data Security and Integrity:** Protects data from accidental or unauthorized modification.
* **Modularity and Reusability:** Promotes the creation of self-contained, reusable components.
* **Maintainability:** Easier to modify and update code within a class without affecting external code that interacts with it.
* **Flexibility:** Allows for changes in internal implementation details without requiring changes in the public interface.
