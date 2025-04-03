#include "refugio.hpp"

Refugio::Refugio(const std::string& name, const std::string& leader)
    : EntidadGenerica(name)
    , m_leader(leader)
{
}

void Refugio::showInfo() const
{
    std::cout << "🏠 Refugio: " << m_name << "\t A cargo de: " << m_leader << "\n";
    std::cout << "\t🛡️  Defensa: " << m_defense << "\n";
    std::cout << "\t⚔️  Ataque: " << m_attack << "\n";
    std::cout << "👥 Moradores: ";
    for (int refugee = 0; refugee < m_refugees.size(); refugee++)
    {
        std::cout << "\t - " << m_refugees.at(refugee) << std::endl;
    }
    std::cout << "\n";
    std::cout << "\t📦 Recursos: \n";
}

void Refugio::doAction() const
{
    throw std::runtime_error("Not implemented yet");
}

void Refugio::addRefugee(const std::string& refugee)
{
    m_refugees.push_back(refugee);
    std::cout<< "se ha añadido el morador" << refugee << "al refugio 33" <<std::endl;

}

void Refugio::addResource(const std::string& resource, float amount)
{
    m_resources.push_back(std::pair(resource,amount));
}

bool Refugio::consumeResource(const std::string& resource, float amount)
{
    for (auto it=m_resources.begin(); it != m_resources.end(); ++it )
    {
        if (it->first == resource)
        {
            if (it->second >= amount)
            {
                it->second -= amount;
                std::cout << "Se ha consumido "<<amount<<" de "<<resource<<std::endl;
                return true;
            }
            else
            {
                std::cout << "No hay suficiente recurso" << std::endl;
                return false;
            }
        }
        std::cout << "No hay recurso con ese nombre" << std::endl; return false;
    }
}

void Refugio::registerVisitant(const std::string& nombre, const EngineData::Faction faccion)
{
    if (!isSafeFaction(faccion))
    {
       std::cout << "Acceso denegado: La facción " << faccionToString(faccion) << " no es segura para el refugio."
        << std::endl;
        return;
    }

    Visitante nuevoVisitante {nombre, faccion};
    m_visitants->push_front(nuevoVisitante);
    std::cout << "Visitante: " << nombre << " registrado existosamente en el refugio." << std::endl;
}

void Refugio::showVisits()
{
    std::cout << "📖 Registro de visitas al Refugio " << m_name << ":\n";
    printRecursive(m_visitants->get_head());
}

void Refugio::printRecursive(DoublyListNode<Visitante>* mNode)
{
    if (!mNode)
    {
        std::cout << "Fin del registro!" << std::endl;
        return;
    }
    std::cout<<"visitante: "<<mNode->data.nombre;
    std::cout<<"\n";
    printRecursive(mNode->next);
}
bool Refugio::hasFactionVisited(EngineData::Faction faccion) const
{
    auto it=m_visitants->get_head();
    while (it != nullptr)
        {
            if (it->data.faccion == faccion){return true;}
            if (it == nullptr){return false;}
            it = it->next;
        }
}


bool Refugio::isSafeFaction(const EngineData::Faction faccion) const
{
    return (faccion == EngineData::Faction::REFUGEES || faccion == EngineData::Faction::WATER_MERCHANTS ||
            faccion == EngineData::Faction::MERCHANTS || faccion == EngineData::Faction::STEEL_BROTHERS ||
            faccion == EngineData::Faction::CARAVAN);
}
