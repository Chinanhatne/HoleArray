#ifndef __HOLEARRAY_H__
#define __HOLEARRAY_H__
#include <string>
using std::string; // For printing purpose
template <typename T>
class HoleArray
{
private:
    class Hole
    {
    public:
        int index;
        int size;
        Hole *next;
        Hole(int index, int size, Hole *next = nullptr) : index(index), size(size), next(next) {}
    };

public:
    HoleArray();
    ~HoleArray();

public:
    void append(T item);
    void insert(T item, int index);
    T remove(int item_index);

public:
    T replace(int item_index, T item);

public:
    T get(int item_index) { return array[transverseIndex(item_index)]; }

public:
    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    int getAllHolesSize() const { return all_holes_size; }
    int getHoleSum() { return holeSum(); }
    int getRealSize() { return size + all_holes_size; }

public:
    string toString();

private:
    T *array;
    int capacity;
    int size;

private:
    Hole *head;

public:
    string printHoles();

private:
    int capacity_growth_multiplier = 2;

private:
    void expandCapacity(int new_capacity);
    void ensureCapacity(int _size);

private:
    int all_holes_size;

private:
    int holeSum();
    int transverseIndex(int item_index);
    int transverseIndexGetHole(int item_index, Hole **prev, Hole **curr);
    void insertHoleBetween(int hole_index, int hole_size, Hole *prev, Hole *curr);
};

template <typename T>
HoleArray<T>::HoleArray() : array(nullptr), capacity(0), size(0), head(nullptr), all_holes_size(0) {}

template <typename T>
HoleArray<T>::~HoleArray()
{
    delete[] array;
    Hole *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void HoleArray<T>::expandCapacity(int new_capacity)
{
    T *new_cap_array = new T[new_capacity];
    for (int i = 0; i < capacity; i++)
    {
        new_cap_array[i] = array[i];
    }
    delete[] array;
    array = new_cap_array;
    capacity = new_capacity;
}

template <typename T>
void HoleArray<T>::ensureCapacity(int _size)
{
    if (_size > capacity)
    {
        expandCapacity(capacity * capacity_growth_multiplier + 1);
    }
}

template <typename T>
int HoleArray<T>::holeSum()
{
    int sum = 0;
    Hole *temp = head;
    while (temp != nullptr)
    {
        sum += temp->size;
        temp = temp->next;
    }
    return sum;
}

template <typename T>
int HoleArray<T>::transverseIndex(int item_index)
{
    int adjust_index = item_index;
    Hole *temp = head;
    while (temp != nullptr && temp->index < adjust_index)
    {
        adjust_index += temp->size;
        temp = temp->next;
    }
    return adjust_index;
}

template <typename T>
int HoleArray<T>::transverseIndexGetHole(int item_index, Hole **prev, Hole **curr)
{
    int adjust_index = item_index;
    *prev = nullptr;
    *curr = head;

    while (*curr != nullptr && (*curr)->index < adjust_index)
    {
        adjust_index += (*curr)->size;
        *prev = *curr;
        *curr = (*curr)->next;
    }
    return adjust_index;
}

template <typename T>
void HoleArray<T>::insertHoleBetween(int hole_index, int hole_size, Hole *prev, Hole *curr)
{
    Hole *new_hole = new Hole(hole_index, hole_size, nullptr);
    if (prev != nullptr)
    {
        prev->next = new_hole;
    }
    else
    {
        head = new_hole;
    }
    new_hole->next = curr;
}

template <typename T>
void HoleArray<T>::append(T item)
{
    ensureCapacity(size + all_holes_size + 1);
    array[size + all_holes_size] = item;
    size++;
}

template <typename T>
T HoleArray<T>::remove(int item_index)
{
    Hole *prev = nullptr;
    Hole *curr = nullptr;
    int adjust_index = transverseIndexGetHole(item_index, &prev, &curr);
    T removed_item = array[adjust_index];

    if (curr != nullptr && curr->index == adjust_index)
    {
        curr->size += 1;
    }
    else
    {
        insertHoleBetween(adjust_index, 1, prev, curr);
    }

    all_holes_size += 1;
    size--;
    return removed_item;
}

template <typename T>
T HoleArray<T>::replace(int item_index, T item)
{
    int adjust_index = transverseIndex(item_index);
    T old_item = array[adjust_index];
    array[adjust_index] = item;
    return old_item;
}

template <typename T>
void HoleArray<T>::insert(T item, int item_index)
{
    Hole *prev = nullptr;
    Hole *curr = nullptr;
    int adjust_index = transverseIndexGetHole(item_index, &prev, &curr);

    if (curr != nullptr && curr->index == adjust_index)
    {
        if (curr->size == 1)
        {
            if (prev != nullptr)
            {
                prev->next = curr->next;
            }
            else
            {
                head = curr->next;
            }
            delete curr;
        }
        else
        {
            curr->index += 1;
            curr->size -= 1;
        }
        all_holes_size -= 1;
    }
    else
    {
        ensureCapacity(size + all_holes_size + 1);
        for (int i = size + all_holes_size; i > adjust_index; i--)
        {
            array[i] = array[i - 1];
        }
    }
    array[adjust_index] = item;
    size++;
}
template <typename T>
string HoleArray<T>::toString()
{
    string result = "[";
    for (int i = 0; i < size + all_holes_size; i++)
    {
        if (i >= 0 && i < size + all_holes_size)
        {
            Hole *temp = head;
            while (temp != nullptr)
            {
                if (temp->index == i)
                {
                    result += "_, ";
                    break;
                }
                temp = temp->next;
            }
            if (temp != nullptr)
            {
                continue;
            }
        }
        result += std::to_string(array[i]);
        if (i != size + all_holes_size - 1)
        {
            result += ", ";
        }
    }
    result += "]";
    return result;
}

template <typename T>
string HoleArray<T>::printHoles()
{
    string result = "Holes: ";
    Hole *temp = head;
    while (temp != nullptr)
    {
        result += "(idx: " + std::to_string(temp->index) + ", size: " + std::to_string(temp->size) + ") ";
        result += "-> ";
        temp = temp->next;
    }
    return result;
}

#endif // __HOLEARRAY_H__