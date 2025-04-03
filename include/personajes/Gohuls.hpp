//
// Created by Rocco on 3/4/2025.
//

#ifndef GOHULS_H
#define GOHULS_H
#include "engine.hpp"
#include "engineData.hpp"
#include "entidadGenerica.hpp"
#include "list.hpp"
#include "wrapperVector.hpp"
#include <iostream>
#include <string>
#include <utility>


class Ghoul : public EntidadGenerica{
    protected :
    float m_health;   //defino atributos genericos de personajes
    float m_strength;
    float m_energy;
public:
    /**
     * @brief Constructor de personaje
     *
     * @param name Nombre del personaje
     * @param strength Nivel de fuerza inicial del personaje
     * @param energy energia inicial del personaje
     */
    Ghoul(const std::string& name, float strength, float energy);
    //muestra la informacion del gohul
    void showInfo() const override;
    //accion especifica del gohul
    void doAction() const;
};
#endif //GOHULS_H
