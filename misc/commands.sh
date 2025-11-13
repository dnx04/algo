# lệnh dịch và flag để debug
g++ -fdiagnostics-color=always -std=gnu++20 -O2 -g -static -Wall -Wextra -Warith-conversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_FORTIFY_SOURCE=2 -DLOCAL -fstack-protector
# kiểm tra sha1 để đảm bảo gõ template đúng, 8 kí tự hex trong description là 8 kí tự đầu sha1sum của code sau khi đã bỏ hết dấu cách, comment, tab, xuống dòng,...
cpp -dD -P -fpreprocessed file_name | tr -d '[:space:]'| sha1sum | cut -c-8