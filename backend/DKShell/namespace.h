#ifndef NAMESPACE
#define NAMESPACE
#define Q_DECLARE_METATYPE2(TYPE, NAME )
QT_BEGIN_NAMESPACE
template <>
struct QMetaTypeId< TYPE >
{
enum { Defined = 1 };
static int qt_metatype_id()
{
static QBasicAtomicInt metatype_id = Q_BASIC_ATOMIC_INITIALIZER(0);
if (!metatype_id)
metatype_id = qRegisterMetaType< TYPE >(#NAME,
reinterpret_cast< TYPE *>(quintptr(-1)));
return metatype_id;
}
};
QT_END_NAMESPACE
#endif // NAMESPACE

