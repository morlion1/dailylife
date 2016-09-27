#!/bin/bash
echo "now cam"
raspistill -o /japi/japi/image/now.jpeg
echo "image proc"
/japi/japi2/Japi
echo "send db"
/japi/db/db




