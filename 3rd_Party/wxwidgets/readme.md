���벽��:
1.git clone������,����wxwidgets����ģ��;
2.�����ļ�"wxWidgets/include/wx/msw/setup0.h"�� "wxWidgets/include/wx/msw/setup.h"
3.STL����,�޸� wxWidgets/include/wx/msw/setup.h��, wxUSE_STL = 1
4.���нű�:make_wxWidgets.bat

ʹ�ò���:
1.�޸��ļ�:build_target/lib/vc_x64_dll/mswud/wx/setup.h
    ����:
    #define wxMONOLITHIC 1
    #define  wxNO_GL_LIB
    ������CmakeLists�ж���
    
2.�ο� usewxwidget.cmake �����Լ�ģ���CmakeLists
