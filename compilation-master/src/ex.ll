; ModuleID = 'ex.o'
target datalayout = "e-p:32:32-i64:64-v128:32:128-n32-S128"
target triple = "asmjs-unknown-emscripten"

@w = common global float 0.000000e+00
@h = common global float 0.000000e+00
@angle = common global float 0.000000e+00
@angle_dir = common global i32 0
@N = common global i32 0

declare void @background(i32)

declare void @fill(i32)

declare void @stroke(i32)

declare void @ellipse(i32, i32, i32, i32)

; Function Attrs: nounwind readnone
declare float @sinf(float)

; Function Attrs: nounwind readnone
declare float @cosf(float)


; Function Attrs: nounwind
define void @my_setup() {
  store float 6.400000e+02, float* @w
  store float 4.800000e+02, float* @h
  store float 0.000000e+00, float* @angle
  store i32 0, i32* @angle_dir
  store i32 200, i32* @N
  %1 = load float, float* @w
  %2 = fptosi float %1 to i32
  %3 = load float, float* @h
  %4 = fptosi float %3 to i32
  call void @createCanvas(i32 %2, i32 %4)
  ret void
}

declare void @createCanvas(i32, i32)

; Function Attrs: nounwind
define void @my_draw() {
  %1 = alloca i32
  %2 = alloca float
  call void @background(i32 0)
  store i32 0, i32* %1
  br label %3

; <label>:3:                                      ; preds = %60, %0
  %4 = load i32, i32* %1
  %5 = load i32, i32* @N
  %6 = icmp slt i32 %4, %5
  br i1 %6, label %7, label %63

; <label>:7:                                      ; preds = %3
  %8 = load i32, i32* %1
  %9 = sitofp i32 %8 to double
  %10 = fmul double 2.550000e+02, %9
  %11 = load i32, i32* @N
  %12 = sitofp i32 %11 to double
  %13 = fdiv double %10, %12
  %14 = fptosi double %13 to i32
  call void @fill(i32 %14)
  %15 = load i32, i32* @N
  %16 = load i32, i32* %1
  %17 = sub nsw i32 %15, %16
  %18 = sitofp i32 %17 to double
  %19 = fmul double 2.550000e+02, %18
  %20 = load i32, i32* @N
  %21 = sitofp i32 %20 to double
  %22 = fdiv double %19, %21
  %23 = fptosi double %22 to i32
  call void @stroke(i32 %23)
  %24 = load i32, i32* %1
  %25 = sitofp i32 %24 to float
  %26 = load float, float* @angle
  %27 = fadd float %25, %26
  store float %27, float* %2
  %28 = load float, float* @w
  %29 = fpext float %28 to double
  %30 = fdiv double %29, 2.000000e+00
  %31 = load i32, i32* %1
  %32 = sitofp i32 %31 to float
  %33 = load float, float* %2
  %34 = call float @sinf(float %33)
  %35 = fmul float %32, %34
  %36 = fpext float %35 to double
  %37 = fadd double %30, %36
  %38 = fptosi double %37 to i32
  %39 = load float, float* @h
  %40 = fpext float %39 to double
  %41 = fdiv double %40, 2.000000e+00
  %42 = load i32, i32* %1
  %43 = sitofp i32 %42 to float
  %44 = load float, float* %2
  %45 = call float @cosf(float %44)
  %46 = fmul float %43, %45
  %47 = fpext float %46 to double
  %48 = fadd double %41, %47
  %49 = fptosi double %48 to i32
  %50 = load i32, i32* %1
  %51 = sitofp i32 %50 to float
  %52 = load float, float* @angle
  %53 = fmul float %51, %52
  %54 = fptosi float %53 to i32
  %55 = load i32, i32* %1
  %56 = sitofp i32 %55 to float
  %57 = load float, float* @angle
  %58 = fmul float %56, %57
  %59 = fptosi float %58 to i32
  call void @ellipse(i32 %38, i32 %49, i32 %54, i32 %59)
  br label %60

; <label>:60:                                     ; preds = %7
  %61 = load i32, i32* %1
  %62 = add nsw i32 %61, 1
  store i32 %62, i32* %1
  br label %3

; <label>:63:                                     ; preds = %3
  %64 = load i32, i32* @angle_dir
  %65 = icmp eq i32 %64, 0
  br i1 %65, label %66, label %75

; <label>:66:                                     ; preds = %63
  %67 = load float, float* @angle
  %68 = fpext float %67 to double
  %69 = fadd double %68, 1.000000e-02
  %70 = fptrunc double %69 to float
  store float %70, float* @angle
  %71 = load float, float* @angle
  %72 = fcmp ogt float %71, 2.000000e+00
  br i1 %72, label %73, label %74

; <label>:73:                                     ; preds = %66
  store i32 1, i32* @angle_dir
  br label %74

; <label>:74:                                     ; preds = %73, %66
  br label %88

; <label>:75:                                     ; preds = %63
  %76 = load i32, i32* @angle_dir
  %77 = icmp eq i32 %76, 1
  br i1 %77, label %78, label %87

; <label>:78:                                     ; preds = %75
  %79 = load float, float* @angle
  %80 = fpext float %79 to double
  %81 = fsub double %80, 1.000000e-02
  %82 = fptrunc double %81 to float
  store float %82, float* @angle
  %83 = load float, float* @angle
  %84 = fcmp olt float %83, -2.000000e+00
  br i1 %84, label %85, label %86

; <label>:85:                                     ; preds = %78
  store i32 0, i32* @angle_dir
  br label %86

; <label>:86:                                     ; preds = %85, %78
  br label %87

; <label>:87:                                     ; preds = %86, %75
  br label %88

; <label>:88:                                     ; preds = %87, %74
  ret void
}
