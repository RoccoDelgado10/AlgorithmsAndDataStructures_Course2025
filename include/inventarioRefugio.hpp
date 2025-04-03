/*
 * Inventario del Refugio 33
 * Copyright (C) 2025, AyED COM-VIRTUAL
 * Marzo 13, 2025.
 */

#ifndef _INVENTARIO_REFUGIO_HPP
#define _INVENTARIO_REFUGIO_HPP

#include <iostream>
#include <string>

/**
 * @brief Clase que representa un objeto de tipo WrapperVectorInventario. Una implementación de un vector para el
 * inventario del refugio.
 */
class WrapperVectorInventario
{
private:
    std::string* m_data; //< Puntero a un string que representa el inventario del refugio.
    size_t m_size;       //< Tamaño del inventario del refugio.
    size_t m_capacity;   //< Capacidad del inventario del refugio.

    /**
     * @brief Método que se encarga de redimensionar el inventario del refugio.
     */
    void resize(){ //es como el metodo expandir
      m_capacity = (m_capacity == 0) ? 100 : m_capacity * 2;
      auto* nuevo_data = new std::string[m_capacity];
      for (std::string* ptr = m_data; ptr < m_data + m_size; ++ptr) {
       nuevo_data[ptr - m_data] = *ptr;
      }
      delete[] m_data;
      m_data = nuevo_data;
    };

public:
    /**
     * @brief Constructor de la clase WrapperVectorInventario.
     */
    WrapperVectorInventario()
        : m_data(nullptr)
        , m_size(0)
        , m_capacity(0) {};

    /**
     * @brief Destructor de la clase WrapperVectorInventario.
     */
    ~WrapperVectorInventario()
    {
        delete[] m_data;
    }

    /**
     * @brief Método que se encarga de agregar un elemento al inventario del refugio.
     *
     * @param item Elemento a agregar al inventario del refugio.
     */
    void pushBack(const std::string& item)
    {
        if (m_size == m_capacity)
        {
            resize();
        }
        m_data[m_size++] = item;
    }

    /**
     * @brief Método que se encarga de obtener un elemento del inventario del refugio.
     */
    std::string& getAt(size_t index) //el metodo devuelve una referencia a un string, no devuelve una copia
                                     //devuelve un acceso directo al objeto guardado en m_data
    {
        return m_data[index];      //con el podemos modificar directamente el objeto dentro
    }                                //por ej: getAt(2) = "nuevo valor";
    //la funcion getAt que toma como parametro un indice size_t(entero sin signo) que se usa para representar
    // tamaños o indices en contenedores estandar
    /**
     * @brief Método que se encarga de obtener el tamaño del inventario del refugio.
     */
    size_t size() const{
      return m_size;
    };

    /**
     * @brief Método que se encarga de obtener la capacidad del inventario del refugio.
     */
    size_t capacity() const{
      return m_capacity;
    };

    /**
     * @brief Método que se encarga de imprimir el inventario del refugio.
     */
    void print() const{
      if (m_size == 0){
        std::cout<<"Inventario sin elementos"<<std::endl;
        return;
      }
      std::cout << "===Inventario del refugio==== " << std::endl;
      for (auto* ptr = begin(); ptr < end(); ++ptr) {
        std::cout << *ptr << std::endl;
      }
    };

    /**
     * @brief Método que se encarga de eliminar el último elemento del inventario del refugio.
     */
    void popBack(){
      if (m_size == 0){
        std::cout<<"Inventario sin elementos, no se puede eliminar elemento"<<std::endl;
        return;
      }
      std::destroy_at(&m_data[m_size - 1]); // Destruimos el último elemento
      --m_size;
    };

    /**
     * @brief Iterador final del inventario del refugio.
     */
    std::string* end() const
    {
        return m_data + m_size;
    }

    /**
     * @brief Iterador comienzo del inventario del refugio.
     */
    std::string* begin() const{
      return m_data;
    };

    /**
     * @brief Intercambiar dos WrapperVectorInventario. (Swap)
     */
    void swap(WrapperVectorInventario& other){
      /*auto* ptr = m_data;
      m_data = other.m_data;
      m_size = other.m_size;
      other.m_data = ptr;
      other.m_size = m_size;*/
      std::swap(m_data, other.m_data);
      std::swap(m_size, other.m_size);
      std::swap(m_capacity, other.m_capacity); //swap implementado por c++ mas seguro y eficiente
    };
};
#endif // _INVENTARIO_REFUGIO_HPP