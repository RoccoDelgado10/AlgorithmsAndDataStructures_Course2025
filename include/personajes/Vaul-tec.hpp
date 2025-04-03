//
// Created by Rocco on 3/4/2025.
//

#ifndef VAUL_TEC_H
#define VAUL_TEC_H

#include "engine.hpp"
#include "engineData.hpp"
#include "entidadGenerica.hpp"
#include "list.hpp"
#include "wrapperVector.hpp"
#include <iostream>
#include <string>
#include <utility>


class Vaul_tec : public EntidadGenerica{
    protected :
        float m_health;   //defino atributos genericos de personajes
    float m_strength;
    float m_energy;
    int m_number;
public:
    /**
     * @brief Constructor de vaul-tec
     *
     * @param name Nombre del refugiado
     * @param strength Nivel de fuerza inicial del refugiado
     * @param energy energia inicial del refugiado
    * @param numero del refugiado.
     */
    Vaul_tec(const std::string& name, float strength, float energy, int number);
    void showInfo() const override;
    void doAction() const;
};


#endif //VAUL_TEC_H
