file=$1
sed -E -i \
    -e 's|HTTP/1.0|HTTP/1.1|g' \
    -e '/^#/d' \
    -e 's|[0-9]{4}-?[0-9]{4}-?[0-9]{4}-?[0-9]{4}|XXXX-XXXX-XXXX-XXXX|g' \
    $file