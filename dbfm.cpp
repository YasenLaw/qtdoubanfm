#include "dbfm.h"

Dbfm::Dbfm()
{
}

void Dbfm::init(QString json)
{
    QScriptValue sc;
    QScriptEngine engine;
    sc = engine.evaluate("value = " + json);//ע�����������ô�á���֪��Ϊʲô��û��ȥ�о���
    int i=0;

    if (sc.property("song").isArray())
    {
             QScriptValueIterator it(sc.property("song"));
             while (it.hasNext())
             {
                 it.next();
                 song[i].init(it.value(),i);
                 i++;
             }
    }
    num = i-1;
}



