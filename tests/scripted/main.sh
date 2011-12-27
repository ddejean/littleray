#/bin/bash

# Ask for help
build/littleray --help &> /dev/null
# Test invalid argument
build/littleray --machin truc &> /dev/null
# Test bad display type
build/littleray --scene scene.xml --display bad-display &> /dev/null
# Test default render with sample scene
build/littleray --scene scene.xml --display none &> /dev/null
