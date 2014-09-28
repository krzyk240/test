
test:
	@echo "server {"
	@echo "    listen 127.2.2.2:80 default; ## listen for ipv4"
	@echo "    # listen [::]:80 default ipv6only=on; ## listen for ipv6"
	@echo ""
	@echo "    # server_name localhost;"
	@echo "    server_name_in_redirect off;"
	@echo ""
	@echo "    charset utf-8;"
	@echo ""
	@echo "    access_log "'$(INSTALL_DIR)'"access.log;"
	@echo "    error_log "'$(INSTALL_DIR)'"error.log;"
	@echo ""
	@echo "    root "'$(INSTALL_DIR)'"public/;"
	@echo "    index index.php index.html index.htm;"
	@echo ""
	@echo "    location / {"
	@echo "        try_files \$$uri \$$uri/ =404;"
	@echo "    }"
	@echo ""
	@echo "    location ~ \\.php\$$ {"
	@echo "        try_files \$$uri =404;"
	@echo "        fastcgi_split_path_info ^(.+\\.php)(/.+)\$$;"
	@echo "        fastcgi_pass "$(shell var=`grep "listen =" /etc/php5/fpm/pool.d/www.conf | tail -c+10`; first=`echo $${var} | head -c1`; if [ "$$first" = "/" ]; then echo "unix:$$var"; else echo $$var; fi)";"
	@echo "        fastcgi_index index.php;"
	@echo "        include fastcgi_params;"
	@echo "    }"
	@echo "}"