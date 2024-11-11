#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

const float groundLevel = 500;
const float jumpHeight = 200;
const float jumpDuration = 1.0f;
const float windowWidth = 800;
const float windowHeight = 600;
float quadraticA, quadraticB, quadraticC;

void calculateJumpCoefficients() {
    float t1 = 0.0f;
    float t2 = 0.5f;
    float t3 = 1.0f;

    float y1 = groundLevel;
    float y2 = groundLevel - jumpHeight;
    float y3 = groundLevel;

    quadraticC = y1;
    quadraticB = (y2 - y1 - (t2 * t2 - t1 * t1) * (y3 - y1) / (t3 * t3 - t1 * t1)) / (t2 - t1);
    quadraticA = (y3 - y1 - quadraticB * (t3 - t1)) / (t3 * t3 - t1 * t1);
}

sf::Vector2f lerp(const sf::Vector2f& start, const sf::Vector2f& end, float t) {
    return start + (end - start) * t;
}

int main() {
    calculateJumpCoefficients();

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Parallax Jump with Sprite");
    window.setFramerateLimit(20);

    // Load background textures for parallax layers
    sf::Texture parallaxTexture1, parallaxTexture2, parallaxTexture3, parallaxTexture4;
    parallaxTexture1.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/background_1.png");
    parallaxTexture2.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/background_2.png");
    parallaxTexture3.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/background_3.png");
    parallaxTexture4.loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/background_4.png");

    sf::Sprite layer1(parallaxTexture1);
    sf::Sprite layer2(parallaxTexture2);
    sf::Sprite layer3(parallaxTexture3);
    sf::Sprite layer4(parallaxTexture4);

    layer1.setScale(windowWidth / parallaxTexture1.getSize().x, windowHeight / parallaxTexture1.getSize().y);
    layer2.setScale(windowWidth / parallaxTexture2.getSize().x, windowHeight / parallaxTexture2.getSize().y);
    layer3.setScale(windowWidth / parallaxTexture3.getSize().x, windowHeight / parallaxTexture3.getSize().y);
    layer4.setScale(windowWidth / parallaxTexture4.getSize().x, windowHeight / parallaxTexture4.getSize().y);

    float layer1ScrollSpeed = 10.0f, layer2ScrollSpeed = 20.0f, layer3ScrollSpeed = 30.0f, layer4ScrollSpeed = 40.0f;
    float layer1Offset = 0.0f, layer2Offset = 0.0f, layer3Offset = 0.0f, layer4Offset = 0.0f;

    // Load adventurer jump animation textures
    sf::Texture adventurerTextures[4];
    adventurerTextures[0].loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/adventurer-jump-00.png");
    adventurerTextures[1].loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/adventurer-jump-01.png");
    adventurerTextures[2].loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/adventurer-jump-02.png");
    adventurerTextures[3].loadFromFile("C:/Users/omart/OneDrive/Documents/GitHub/MathGameDev/SfmlTests/adventurer-jump-03.png");

    sf::Sprite adventurer(adventurerTextures[0]);
    adventurer.setPosition(20, groundLevel);
    adventurer.setScale(2.0f, 2.0f);

    bool isJumping = false;
    float jumpElapsedTime = 0.0f;
    int currentFrame = 0;
    sf::Clock animationClock;
    sf::Clock parallaxClock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                if (!isJumping) {
                    isJumping = true;
                    jumpElapsedTime = 0.0f;
                    currentFrame = 0;
                }
            }
        }

        float deltaTime = parallaxClock.restart().asSeconds();
        layer1Offset -= layer1ScrollSpeed * deltaTime;
        layer2Offset -= layer2ScrollSpeed * deltaTime;
        layer3Offset -= layer3ScrollSpeed * deltaTime;
        layer4Offset -= layer4ScrollSpeed * deltaTime;

        float layer1Width = layer1.getLocalBounds().width * layer1.getScale().x;
        float layer2Width = layer2.getLocalBounds().width * layer2.getScale().x;
        float layer3Width = layer3.getLocalBounds().width * layer3.getScale().x;
        float layer4Width = layer4.getLocalBounds().width * layer4.getScale().x;

        if (layer1Offset <= -layer1Width) layer1Offset += layer1Width;
        if (layer2Offset <= -layer2Width) layer2Offset += layer2Width;
        if (layer3Offset <= -layer3Width) layer3Offset += layer3Width;
        if (layer4Offset <= -layer4Width) layer4Offset += layer4Width;

        if (isJumping) {
            jumpElapsedTime += 1.0f / 20.0f;

            if (animationClock.getElapsedTime().asSeconds() > 0.1f) {
                currentFrame = (currentFrame + 1) % 4;
                adventurer.setTexture(adventurerTextures[currentFrame]);
                animationClock.restart();
            }

            float yPosition = quadraticA * jumpElapsedTime * jumpElapsedTime + quadraticB * jumpElapsedTime + quadraticC;
            adventurer.setPosition(20, yPosition);

            if (jumpElapsedTime >= jumpDuration) {
                isJumping = false;
                adventurer.setPosition(20, groundLevel);
                adventurer.setTexture(adventurerTextures[0]);
            }
        }

        window.clear();

        layer1.setPosition(layer1Offset, 0);
        window.draw(layer1);
        layer1.setPosition(layer1Offset + layer1Width, 0);
        window.draw(layer1);

        layer2.setPosition(layer2Offset, 0);
        window.draw(layer2);
        layer2.setPosition(layer2Offset + layer2Width, 0);
        window.draw(layer2);

        layer3.setPosition(layer3Offset, 0);
        window.draw(layer3);
        layer3.setPosition(layer3Offset + layer3Width, 0);
        window.draw(layer3);

        layer4.setPosition(layer4Offset, 0);
        window.draw(layer4);
        layer4.setPosition(layer4Offset + layer4Width, 0);
        window.draw(layer4);

        window.draw(adventurer);

        window.display();
    }

    return 0;
}
