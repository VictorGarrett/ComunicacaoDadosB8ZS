#include "graph.h"

Graph::Graph(): xAxis(sf::LineStrip, 2), yAxis(sf::LineStrip, 2), line(sf::LineStrip){
    
}

Graph::~Graph(){

}

void Graph::draw(sf::RenderTarget& target, sf::RenderStates states) const{
        
        //draw background
        
        //draw axes
        //target.draw(m_sprite, states);
        target.draw(xAxis, states);
        target.draw(yAxis, states);

        //draw line
        target.draw(line, states);
}


void Graph::setPosition(sf::Vector2f pos){
    boundary.left = pos.x;
    boundary.top = pos.y;

    fitAxes();
    fitData();
}


void Graph::setSize(sf::Vector2f size){
    boundary.width = size.x;
    boundary.height = size.y;

    fitAxes();
    fitData();
}

void Graph::setData(std::vector<sf::Vector2f>& data){
    this->data = data;
    fitData();
}

void Graph::setRange(float xMin, float xMax, float yMin, float yMax){
    
    this->xMin = xMin;
    this->xMax = xMax;
    this->yMin = yMin;
    this->yMax = yMax;

    xRange = xMax - xMin;
    yRange = yMax - yMin;

    fitAxes();
    fitData();
}

void Graph::fitAxes(){

    sf::Vector2f apparentOrigin;

    origin.x = (boundary.width/xRange)*(-1*xMin);
    if(origin.x < 0)
        apparentOrigin.x = 0;
    else if(origin.x > boundary.width)
        apparentOrigin.x = boundary.width;
    else
        apparentOrigin.x = origin.x;

    origin.y = (boundary.height/yRange)*yMax;
    if(origin.y < 0)
        apparentOrigin.y = 0;
    else if(origin.y > boundary.height)
        apparentOrigin.y = boundary.height;
    else
        apparentOrigin.y = origin.y;

    xAxis[0].position = sf::Vector2f(boundary.left, boundary.top + apparentOrigin.y);
    xAxis[1].position = sf::Vector2f(boundary.left + boundary.width, boundary.top + apparentOrigin.y);

    yAxis[0].position = sf::Vector2f(boundary.left + apparentOrigin.x, boundary.top + boundary.height);
    yAxis[1].position = sf::Vector2f(boundary.left + apparentOrigin.x, boundary.top);
}

void Graph::fitData(){

    line.clear();

    for(auto i = data.begin(); i != data.end(); i++){
        printf("point fit\n");
        sf::Vector2f position(boundary.left + origin.x + (boundary.width/xRange)*(i->x), boundary.top + origin.y - (boundary.height/yRange)*(i->y));
        sf::Vertex point(position, sf::Color::Yellow); 
        line.append(point);
    }
}