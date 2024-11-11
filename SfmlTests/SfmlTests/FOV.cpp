//#include <SFML/Graphics.hpp>
//#include <cmath>
//
//const float PI = 3.14159265f;
//
//void drawArc(sf::RenderWindow& window, sf::Vector2f center, float radius, float startAngle, float endAngle, sf::Color color) {
//    sf::VertexArray arc(sf::TriangleFan);
//    arc.append(sf::Vertex(center, color));
//
//    int points = 30;
//    for (int i = 0; i <= points; ++i) {
//        float angle = startAngle + i * (endAngle - startAngle) / points;
//        sf::Vector2f point = center + sf::Vector2f(std::cos(angle * PI / 180) * radius, std::sin(angle * PI / 180) * radius);
//        arc.append(sf::Vertex(point, color));
//    }
//
//    window.draw(arc);
//}
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "FOV");
//    window.setFramerateLimit(60);
//
//    sf::CircleShape circleA(20.0f);
//    circleA.setFillColor(sf::Color::Blue);
//    circleA.setOrigin(circleA.getRadius(), circleA.getRadius());
//    circleA.setPosition(400, 300);
//
//    sf::CircleShape circleB(20.0f);
//    circleB.setFillColor(sf::Color::Green);
//    circleB.setOrigin(circleB.getRadius(), circleB.getRadius());
//    circleB.setPosition(100, 100);
//
//    float fovRadius = 150.0f;
//    float fovAngle = 60.0f;
//    float fovStartAngle = -fovAngle / 2;
//    sf::Color fovColor = sf::Color(0, 255, 0, 100);
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//            circleB.move(0, -2);
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//            circleB.move(0, 2);
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//            circleB.move(-2, 0);
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//            circleB.move(2, 0);
//
//        sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);
//        sf::Vector2f direction = mousePos - circleB.getPosition();
//        float angleBtoMouse = std::atan2(direction.y, direction.x) * 180 / PI;
//        sf::Vector2f delta = circleA.getPosition() - circleB.getPosition();
//        float distance = std::sqrt(delta.x * delta.x + delta.y * delta.y);
//        bool isInDistance = distance <= fovRadius;
//
//        float angleToA = std::atan2(delta.y, delta.x) * 180 / PI;
//        float angleDifference = std::abs(angleBtoMouse - angleToA);
//        if (angleDifference > 180) angleDifference = 360 - angleDifference;
//        bool isInAngle = angleDifference <= fovAngle / 2;
//
//        if (isInDistance && isInAngle) {
//            fovColor = sf::Color(255, 0, 0, 100); //in Range
//        }
//        else {
//            fovColor = sf::Color(0, 255, 0, 100); //out of Range
//        }
//
//        window.clear();
//
//        window.draw(circleA);
//        window.draw(circleB);
//        drawArc(window, circleB.getPosition(), fovRadius, angleBtoMouse + fovStartAngle, angleBtoMouse - fovStartAngle, fovColor);
//        window.display();
//    }
//
//    return 0;
//}
