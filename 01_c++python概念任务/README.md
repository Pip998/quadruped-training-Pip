一、文件夹说明：

1.源文件与导出文件：包含从nwwolf仓库中下载下来的urdf文件，以及从URDFstudio中导出的mjcf文件。其中，在导出mjcf时因需要勾选浮动基座选项，故在原urdf文件中赋予了base模块一微小质量以保证能顺利渲染。

2.meshes：即原STL文件包

3.结果视频：包含初步仿真视频以及优化线程后的仿真视频

二、文件说明：

1.black_description.xml：初步仿真的模型描述

2.black_description_optimization：在原模型上对关节处friction添加更贴近现实的改动

3.simulate_laying_dog：仿真的运行逻辑

4.simulate_laying_dog_optimization：优化线程后的运行逻辑

