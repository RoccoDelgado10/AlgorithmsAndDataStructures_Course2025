#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

/**
 * @brief Nodo de lista simplemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
struct ListNode
{
    TData data;
    ListNode* next;

    explicit ListNode(const TData& value)
        : data(value)
        , next(nullptr)
    {
    }
};

/**
 * @brief Implementación de una lista simplemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
class LinkedList
{
private:
    ListNode<TData>* head;

public:
    LinkedList()
        : head(nullptr)
    {
    }

    ~LinkedList()
    {
        while(head != nullptr)
        {
            auto temporalNode = head;
            head = head->next;
            delete temporalNode;
        }
    }

    /**
     * @brief Inserta un nuevo elemento al inicio de la lista
     *
     * @param value Valor a insertar
     */
    void push_front(const TData& value)
    {
        auto node = new ListNode<TData>(value);
            node->next = head;
            head = node;
    }

    /**
    * @brief Remueve un elemento de la lista dada su posición
    *
    * @param position Posición del elemento a remover
    */
    void remove_at(size_t position)
    {
        if (head == nullptr){return;} //si esta vacia no hace nada

        int contador = 0;

        if (position == 0) //caso de posicion 0
        {
            auto temporalNode = head;
            head = head->next;
            delete temporalNode;
            return;
        }
        auto current = head;
        ListNode<TData> previous = nullptr;
        while (current != nullptr && contador < position)
        {
            previous = current;
            current = current->next;
            contador++;
        }
        if (current)
        {
            previous->next = current->next;
            delete current;
        }

    }

    /**
    * @brief Crea una lista nueva de n elementos a partir de una posición dada
    *
    */
    ListNode<TData>* take(size_t startPosition, size_t nElements)
    {
        if (head == nullptr) {return nullptr;}

        auto current = head;
        int contador=0;

        while (current!=nullptr && contador < startPosition)
        {
            current = current->next;
            contador++;
        }
        if (current==nullptr) {return nullptr;}

        //punteros controladores
        ListNode<TData> newhead = nullptr, newtail = nullptr;
        for (size_t i = 0; i < nElements; i++)
        {
            auto copia = new ListNode(current->data);
            if (newhead == nullptr) //primer nodo,es cabeza y cola
            {
                newhead = copia;
                newtail = copia;
            } else //si no es el primer nodo lo mandamos al final de la lista
            {
                newtail->next = copia;
                newtail = copia;
            }
            current = current->next; //avanzamos al siguiente nodo
        }

        return newhead;
    }

    // Devuelve el tamaño de la lista
   /* size_t size() const {
        size_t count = 0;
        auto current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }*/

    /**
     * @brief Imprime todos los elementos de la lista
     */
    void print() const
    {
        ListNode<TData>* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

/**
 * @brief Nodo de lista doblemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
struct DoublyListNode
{
    TData data;
    DoublyListNode* next;
    DoublyListNode* prev;

    explicit DoublyListNode(const TData& value)
        : data(value)
        , next(nullptr)
        , prev(nullptr)
    {
    }
};

/**
 * @brief Implementación de una lista doblemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
class DoublyLinkedList
{
private:
    DoublyListNode<TData>* head;

public:
    DoublyLinkedList()
        : head(nullptr)
    {
    }

    ~DoublyLinkedList()
    {
        while(head != nullptr)
        {
            auto temporalNode = head;
            head = head->next;
            delete temporalNode;
        }
    }

    /**
     * @brief Retorna el primer elemento de la lista
     *
     * @return Primer elemento de la lista
     */
    DoublyListNode<TData>* get_head() const
    {
        return head;
    }

    /**
     * @brief Inserta un nuevo elemento al inicio de la lista
     *
     * @param value Valor a insertar
     */
    void push_front(const TData& value)
    {
        auto node = new DoublyListNode<TData>(value);
        if (head == nullptr)
        {
            head = node;
            return;
        }
            node->next = head;
            head->prev = node;
            node->prev = nullptr;
            head = node;
    }

    /**
     * @brief Inserta un nuevo elemento al final de la lista
     *
     * @param value Valor a insertar
     */
    void push_back(const TData& value)
    {
        auto node = new DoublyListNode<TData>(value);
        if (head == nullptr){head=node; return;}
        node->next = nullptr;
        auto current = head;
        while ( current->next != nullptr)
        {
            current =current->next;
        }
        current->next = node;
        node->prev = current;

    }

    /**
    * @brief Remueve un elemento de la lista dada su posición
    *
    * @param position Posición del elemento a remover
    */
    void remove_at(size_t position)
    {
        if (head == nullptr){return;} //si esta vacia no hace nada
        int contador = 0;
        if (position == 0) //caso de posicion 0
        {
            auto temporalNode = head;
            head = head->next;
            delete temporalNode;
            return;
        }
        auto current = head;
 //       DoublyListNode<TData> previous = nullptr; ya no hace falta guardar un previous
        while (current != nullptr && contador < position)
        {
        //    previous = current;
            current = current->next;
            contador++;
        }
        if (current)
        {
            (current->prev)->next = current->next;
            (current->next)->prev = current->prev;
            delete current;
        }else {return;} //si no se encuntra el nodo retornar
    }

    /**
    * @brief Copia los elementos de otra lista
    *
    * @param other Lista de la cual copiar los elementos
    */
    void copy_list(const DoublyLinkedList& other)
    {
        throw std::runtime_error("Not implemented yet");
    }

    /**
     * @brief Imprime todos los elementos de la lista
     */
    void print() const
    {
        DoublyListNode<TData>* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

#endif // LIST_HPP
