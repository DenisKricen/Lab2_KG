FROM ubuntu:24.04

# Щоб під час встановлення нічого не зависало з питаннями про часовий пояс
ENV DEBIAN_FRONTEND=noninteractive

# Встановлюємо компілятори, CMake і ВЖЕ ЗІБРАНИЙ Qt 6
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    qt6-base-dev \
    qt6-base-dev-tools \
    libgl1-mesa-dev \
    git \
    && rm -rf /var/lib/apt/lists/*

# Створюємо користувача, щоб не сидіти під рутом
ARG USERNAME=ubuntu
USER $USERNAME