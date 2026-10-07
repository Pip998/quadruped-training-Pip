from setuptools import find_packages
from setuptools import setup

setup(
    name='dog_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('dog_msgs', 'dog_msgs.*')),
)
