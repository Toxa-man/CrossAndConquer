/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.11.1
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // D:/Programming/C++ Projects/Qt/CrossAndConquer/client/src/img/cursor.png
  0x0,0x0,0x0,0xaf,
  0x0,
  0x0,0x4,0x67,0x78,0x9c,0xeb,0xc,0xf0,0x73,0xe7,0xe5,0x92,0xe2,0x62,0x60,0x60,
  0xe0,0xf5,0xf4,0x70,0x9,0x62,0x60,0x60,0xb4,0x2,0x61,0xe,0x36,0xa0,0x48,0x9b,
  0xd3,0xbc,0x18,0x6,0x6,0x16,0x3d,0x4f,0x17,0xc7,0x90,0x8a,0x39,0x6f,0x6f,0x1b,
  0x72,0x35,0x18,0x8,0xb8,0x1e,0xec,0xad,0xf8,0xaf,0xfd,0x5a,0x34,0x84,0xe3,0x50,
  0xf2,0x32,0xbf,0x8f,0xab,0x8f,0x9b,0x45,0x1a,0x17,0xf3,0x3a,0xdc,0xf8,0xf8,0x9d,
  0xa1,0xe1,0x6e,0xb,0xdf,0x9,0x61,0x2b,0x5,0xff,0x17,0xd,0x36,0xb,0x99,0x3f,
  0xa1,0x70,0xce,0x89,0xe7,0x5f,0xdf,0x26,0xca,0x70,0xdf,0xe6,0xd7,0xcd,0xa7,0x8b,
  0xd0,0xe4,0x46,0x39,0xa3,0x9c,0x51,0xce,0xe0,0xe7,0x5c,0x3b,0x13,0x53,0xdf,0xcf,
  0x70,0xe3,0xa4,0x2b,0xfb,0x13,0x4e,0xd9,0x9,0xea,0x25,0xe,0xf3,0x2e,0x30,0x56,
  0x3a,0xa1,0x71,0xee,0x6,0x56,0xb1,0x16,0xb3,0x1f,0x3b,0x28,0xe,0x2c,0x40,0x18,
  0x3c,0x5d,0xfd,0x5c,0xd6,0x39,0x25,0x34,0x1,0x0,0xa3,0xd2,0xc5,0xba,
  
};

static const unsigned char qt_resource_name[] = {
  // pictures
  0x0,0x8,
  0xf,0xab,0xc6,0x3,
  0x0,0x70,
  0x0,0x69,0x0,0x63,0x0,0x74,0x0,0x75,0x0,0x72,0x0,0x65,0x0,0x73,
    // img
  0x0,0x3,
  0x0,0x0,0x70,0x37,
  0x0,0x69,
  0x0,0x6d,0x0,0x67,
    // cursor.png
  0x0,0xa,
  0xa,0x68,0xe,0x67,
  0x0,0x63,
  0x0,0x75,0x0,0x72,0x0,0x73,0x0,0x6f,0x0,0x72,0x0,0x2e,0x0,0x70,0x0,0x6e,0x0,0x67,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/pictures
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/pictures/img
  0x0,0x0,0x0,0x16,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x3,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/pictures/img/cursor.png
  0x0,0x0,0x0,0x22,0x0,0x1,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x69,0x54,0xcf,0x52,0x86,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_images)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_images)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_images)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_images)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_images)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_images)(); }
   } dummy;
}
