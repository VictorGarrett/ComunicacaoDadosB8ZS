#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Graph: public sf::Drawable{


public:
    Graph();
    ~Graph();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    //set graph position
    void setPosition(sf::Vector2f pos);

    //set graph boundary size
    void setSize(sf::Vector2f size);

    void setData(std::vector<sf::Vector2f>& data);
    void setRange(float xMin, float xMax, float yMin, float yMax);

    

    //set graph origin relative to boundary top left
    //void setOrigin(sf::Vector2f pos);

private:

    std::vector<sf::Vector2f> data;
    float xMin, xMax, yMin, yMax;
    float xRange, yRange;
    sf::Vector2f origin; //origin position relative to boundary top left
    sf::FloatRect boundary;
    
    sf::VertexArray line;
    sf::VertexArray xAxis, yAxis;

    void fitAxes();
    void fitData();

};