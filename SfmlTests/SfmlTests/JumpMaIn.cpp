//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//const float groundLevelY = 550;
//const float maxJumpHeight = 700;
//const float jumpTotalDuration = 1.0f;
//
//float quadraticA, quadraticB, quadraticC;
//
//void calculateJumpCoefficients() {
//    float timeAtStart = 0.0f;
//    float timeAtPeak = 0.5f;
//    float timeAtEnd = 1.0f;
//
//    float heightAtStart = groundLevelY;
//    float heightAtPeak = groundLevelY - maxJumpHeight;
//    float heightAtEnd = groundLevelY;
//
//    quadraticC = heightAtStart;
//    quadraticB = (heightAtPeak - heightAtStart - (timeAtPeak * timeAtPeak - timeAtStart * timeAtStart) * (heightAtEnd - heightAtStart) / (timeAtEnd * timeAtEnd - timeAtStart * timeAtStart)) / (timeAtPeak - timeAtStart);
//    quadraticA = (heightAtEnd - heightAtStart - quadraticB * (timeAtEnd - timeAtStart)) / (timeAtEnd * timeAtEnd - timeAtStart * timeAtStart);
//}
//
//int main() {
//    calculateJumpCoefficients();
//
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Jump");
//    window.setFramerateLimit(60);
//
//    sf::CircleShape jumper(20.f);
//    jumper.setFillColor(sf::Color::Blue);
//    jumper.setOrigin(jumper.getRadius(), jumper.getRadius());
//    jumper.setPosition(400, groundLevelY);
//
//    bool isJumping = false;
//    float jumpElapsedTime = 0.0f;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
//                if (!isJumping) {
//                    isJumping = true;
//                    jumpElapsedTime = 0.0f;
//                }
//            }
//        }
//
//        if (isJumping) {
//            jumpElapsedTime += 1.0f / 60.0f;
//
//            float yPosition = quadraticA * jumpElapsedTime * jumpElapsedTime + quadraticB * jumpElapsedTime + quadraticC;
//            jumper.setPosition(400, yPosition);
//
//            if (jumpElapsedTime >= jumpTotalDuration) {
//                isJumping = false;
//                jumper.setPosition(400, groundLevelY);
//            }
//        }
//
//        window.clear(sf::Color::Black);
//        window.draw(jumper);
//        window.display();
//    }
//
//    return 0;
//}
