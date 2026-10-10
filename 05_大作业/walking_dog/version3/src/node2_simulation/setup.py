from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'node2_simulation'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),

        # 把 XML 装到 share/node2_simulation/
        (os.path.join('share', package_name),
            glob('node2_simulation/*.xml')),

        # 把 meshes 目录整个装到 share/node2_simulation/meshes/
        (os.path.join('share', package_name, 'meshes'),
            glob('node2_simulation/meshes/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='pip',
    maintainer_email='3554662913@qq.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={'test': ['pytest']},
    entry_points={
        'console_scripts': [
            'simulation = node2_simulation.simulation:main'
        ],
    },
)