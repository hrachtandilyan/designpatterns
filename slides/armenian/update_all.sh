#!/bin/bash

function update_pattern 
{
    PATTERN_TYPE=$1
    PATTERN_NAME=$2
    cd $PATTERN_NAME
    pwd
    #sed -i "" "s/Proxy/${PATTERN_NAME}/g" tex/$PATTERN_NAME.tex
    make clean
    make slides
    cp $PATTERN_NAME.pdf ../../../pdf/$PATTERN_TYPE
    make clean
    ls -l
    cd ..
}

cd src

cd Creational
update_pattern Creational AbstractFactory
update_pattern Creational Builder
update_pattern Creational FactoryMethod
update_pattern Creational Prototype
update_pattern Creational Singleton
cd ..

cd Structural
update_pattern Structural Adapter
update_pattern Structural Bridge
update_pattern Structural Composite
update_pattern Structural Decorator
update_pattern Structural Facade
update_pattern Structural Flyweight
update_pattern Structural Proxy
cd ..

cd Behavioral
update_pattern Behavioral ChainOfResponsibility
update_pattern Behavioral Command
update_pattern Behavioral Interpreter
update_pattern Behavioral Iterator
update_pattern Behavioral Mediator
update_pattern Behavioral Memento
update_pattern Behavioral Observer
update_pattern Behavioral State
update_pattern Behavioral Strategy
update_pattern Behavioral TemplateMethod
update_pattern Behavioral Visitor
cd ..

