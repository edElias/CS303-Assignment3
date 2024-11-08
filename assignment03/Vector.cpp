#ifndef KW_VECTOR_H
#define KW_VECTOR_H

#include <stdexcept>  // For out_of_range exception
using namespace std;

namespace KW {

    template<typename Item_Type>
    class vector {
    private:
        // Data fields
        /** The initial capacity of the array */
        static const size_t INITIAL_CAPACITY = 15;
        /** The current capacity of the array */
        size_t current_capacity;
        /** The current number of items in the array */
        size_t num_items;
        /** The array to contain the data */
        Item_Type* the_data;

        /** Resize the internal array when capacity is exceeded */
        void resize(size_t new_capacity);

    public:
        // Constructors and Destructor
        vector();                      // Default constructor
        ~vector();                     // Destructor
        vector(const vector& other);   // Copy constructor
        vector& operator=(const vector& other);  // Copy assignment operator

        // Member functions
        void push_back(const Item_Type& value);  // Add an element to the end
        Item_Type& operator[](size_t index);     // Access element by index (modifiable)
        const Item_Type& operator[](size_t index) const; // Access element by index (read-only)
        size_t size() const;                     // Get current number of elements
        size_t capacity() const;                 // Get current allocated capacity
        bool is_empty() const;                   // Check if the vector is empty
        void clear();                            // Reset size but keep allocated memory
    };

    // Default constructor
    template<typename Item_Type>
    vector<Item_Type>::vector()
        : current_capacity(INITIAL_CAPACITY), num_items(0), the_data(new Item_Type[INITIAL_CAPACITY]) {}

    // Destructor
    template<typename Item_Type>
    vector<Item_Type>::~vector() {
        delete[] the_data;
    }

    // Copy constructor
    template<typename Item_Type>
    vector<Item_Type>::vector(const vector& other)
        : current_capacity(other.current_capacity), num_items(other.num_items), the_data(new Item_Type[other.current_capacity]) {
        for (size_t i = 0; i < num_items; ++i) {
            the_data[i] = other.the_data[i];
        }
    }

    // Copy assignment operator
    template<typename Item_Type>
    vector<Item_Type>& vector<Item_Type>::operator=(const vector& other) {
        if (this != &other) {
            delete[] the_data;  // Free existing memory
            current_capacity = other.current_capacity;
            num_items = other.num_items;
            the_data = new Item_Type[current_capacity];
            for (size_t i = 0; i < num_items; ++i) {
                the_data[i] = other.the_data[i];
            }
        }
        return *this;
    }

    // Resize function
    template<typename Item_Type>
    void vector<Item_Type>::resize(size_t new_capacity) {
        Item_Type* new_data = new Item_Type[new_capacity];
        for (size_t i = 0; i < num_items; ++i) {
            new_data[i] = the_data[i];
        }
        delete[] the_data;
        the_data = new_data;
        current_capacity = new_capacity;
    }

    // Push back function
    template<typename Item_Type>
    void vector<Item_Type>::push_back(const Item_Type& value) {
        if (num_items == current_capacity) {
            resize(current_capacity * 2);  // Double the capacity when full
        }
        the_data[num_items++] = value;  // Add new item and increment num_items
    }

    // Non-const operator[] (modifiable access)
    template<typename Item_Type>
    Item_Type& vector<Item_Type>::operator[](size_t index) {
        if (index >= num_items) {
            throw out_of_range("Index out of range");
        }
        return the_data[index];
    }

    // Const operator[] (read-only access)
    template<typename Item_Type>
    const Item_Type& vector<Item_Type>::operator[](size_t index) const {
        if (index >= num_items) {
            throw out_of_range("Index out of range");
        }
        return the_data[index];
    }

    // Get current size function
    template<typename Item_Type>
    size_t vector<Item_Type>::size() const {
        return num_items;
    }

    // Get current capacity function
    template<typename Item_Type>
    size_t vector<Item_Type>::capacity() const {
        return current_capacity;
    }

    // Check if vector is empty function
    template<typename Item_Type>
    bool vector<Item_Type>::is_empty() const {
        return num_items == 0;
    }

    // Clear function (resets num_items but keeps allocated memory)
    template<typename Item_Type>
    void vector<Item_Type>::clear() {
        num_items = 0;
    }

} // namespace KW

#endif // KW_VECTOR_H
